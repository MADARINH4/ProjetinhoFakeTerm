#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcaoDaIntegral(double X);
double funcao2derivada(double X);
double calculaImprime(int contador, int contador1, int n, int nCopia, double pontoA, double pontoB, int Cn);
void regraDosTrapezios(int n, double pontoA, double pontoB);
void regraDeSimpson(int n, double pontoA, double pontoB);

int main(void){

    double pontoA = 0;
    double pontoB = 0;
    double h = 0;
    int n = 0;

    system("cls");
    printf("\n\nPontos do intervalo. Ex: 1 2. Digite: ");
    scanf("%lf%lf", &pontoA, &pontoB);
    system("cls");
    printf("\n\nQuantas particoes no intervalo: ");
    scanf("%d", &n);
    system("cls");
    
    regraDosTrapezios(n, pontoA, pontoB);
    system("pause");

    if(n % 2 == 0){

        regraDeSimpson(n, pontoA, pontoB);

    }else{

        printf("\n\nNumero de particoes invalido para esta regra de simpson!\n");
        system("pause");

    }

    return 0;

}

double funcaoDaIntegral(double X){

    return ((4*pow(X, 5)) - 1)/((pow(X, 10)) + 2*(pow(X, 6)) + 2*(pow(X, 5)) + (pow(X, 2)) + (2*X) + 1);

}

double funcao2derivada(double X){

    return (6*((20*pow(X, 13)) - (40*pow(X, 9)) - (85*pow(X, 8)) + (4*pow(X, 5)) + (10*pow(X, 4)) + (20*pow(X, 3)) - 1))/ pow((pow(X, 5) + X + 1), 4);

}

void regraDosTrapezios(int n, double pontoA, double pontoB){

    double resultado = 0;
    double h = 0;
    double Xn = 0;
    int Cn = 1;
    int contador = 0;

    h = (pontoB - pontoA)/(n);

    printf("\n\n\t     REGRA DO TRAPEZIO\n");
    printf("\n  %2s   %13s   %13s   %2s  ", "n", 
    "Xn", "f(Xn)", "Cn");
    printf("\n-------------------------------------------");

    while(contador <= n){

        if(contador == 0){

            resultado = calculaImprime(contador, 0, n, n, pontoA, pontoB, Cn) +  resultado;
            contador++;

        }
        if((contador > 0) && (contador < n)){

            Cn = 2;
            resultado = calculaImprime(contador, 0, n, n, pontoA, pontoB, Cn) +  resultado;
            contador++;

        }
        if(contador == n){
            
            Cn = 1;
            resultado = calculaImprime(contador, 0, n, n, pontoA, pontoB, Cn) +  resultado;
            contador++; 

        }

    }

    printf("\n\nAproximacao Regra do Trapezio s = %.9lf +/- %.9lf\n\n\n", ((h/2)*resultado), fabs(((pow(h, 3))/12) * funcao2derivada(pontoB)));

}

void regraDeSimpson(int n, double pontoA, double pontoB){

    double resultado = 0;
    double resultado1 = 0;
    double Xn = 0;
    double h = 0;
    int Cn = 1;
    int nCopia = 0;
    int contador1 = 0;
    int contador = 0;

    h = (pontoB - pontoA)/(n);

    printf("\n\n\t     REGRA DE SIIMPSON\n");
    printf("\n  %2s   %13s   %13s   %2s  ", "n", 
    "Xn", "f(Xn)", "Cn");
    printf("\n-------------------------------------------");

    while(contador <= n){

        nCopia = n;

        if(contador == 0){

            resultado = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado;
            nCopia = n/2;
            resultado1 = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado1;
            nCopia = n;
            contador++;
            contador1++;

        }
        if((contador > 0) && (contador < n) && ((contador % 2) == 0)){

            Cn = 2;
            resultado = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado;
            contador++;

            if(n % 4 == 0){
                
                nCopia = n/2;

                if((contador1 % 2) != 0){

                    Cn = 4;
                    resultado1 = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado1;
                    contador1++;

                }else{

                    Cn = 2;
                    resultado1 = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado1;
                    contador1++;

                }

                nCopia = n;

            }

        }
        if((contador > 0) && (contador < n) && ((contador % 2) != 0)){

            Cn = 4;
            resultado = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado;
            contador++;

        }
        if(contador == n){

            Cn = 1;
            resultado = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado;
            nCopia = n/2;
            resultado1 = calculaImprime(contador, contador1, n, nCopia, pontoA, pontoB, Cn) + resultado1;
            nCopia = n;
            contador++;
            contador1++;

        }

    }

    if(n % 4 == 0){

        printf("\nAproximacao Regra de Simpson s = %.9lf +/- %.9lf\n\n", (h/3)*resultado, fabs((((h/3)*resultado) - (resultado1))/15));

    }else{

        printf("\nAproximacao Regra de Simpson s = %.9lf\n\n", (h/3)*resultado);

    }

    system("pause");
    
}

double calculaImprime(int contador, int contador1, int n, int nCopia, double pontoA, double pontoB, int Cn){

    double h = 0;
    double Xn = 0;

    if(nCopia == n){
            
        h = (pontoB - pontoA)/(n);
        Xn = (pontoA + (contador*h));
        printf("\n| %2d | %13.9lf | %13.9lf | %2d |",
        contador, Xn, funcaoDaIntegral(Xn), Cn);
        printf("\n-------------------------------------------");
        return funcaoDaIntegral(Xn)*Cn;

    }else{

        h = (pontoB - pontoA)/(nCopia); 
        Xn = (pontoA + (contador1*h));
        return (h/3)*funcaoDaIntegral(Xn)*Cn;

    }

}