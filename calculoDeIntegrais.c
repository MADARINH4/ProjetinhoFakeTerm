#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcaoDaIntegral(double X);
double funcao2derivada(double X);
void preencheTabela(int n, double tabela[][n], double pontoA, double h);
void imprimeTabela(int n, double tabela[][n]);
void regraDosTrapezios(int n, double tabela[][n], double pontoA, double h);
void regraDeSimpson(int n, double tabela[][n], double pontoA, double pontoB, double h);

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
    
    h = (pontoB - pontoA)/n;

    double tabela[n][n];

    preencheTabela(n, tabela, pontoA, h);
    imprimeTabela(n, tabela);
    regraDosTrapezios(n, tabela, pontoA, h);

    if(n % 2 == 0){

        regraDeSimpson(n, tabela, pontoA, pontoB, h);

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

void preencheTabela(int n, double tabela[][n], double pontoA, double h){

    int coluna;
    int linha;
    double Xn = 0;

    for(coluna = 0; coluna < 3; coluna++){

        for(linha = 0; linha <= n; linha++){

            if(coluna == 0)tabela[linha][coluna] = linha;
            if(coluna == 1){

                Xn = (pontoA + (linha*h));
                tabela[linha][coluna] = (pontoA + (linha*h));

            }
            if(coluna == 2){

                Xn = (pontoA + (linha*h));
                tabela[linha][coluna] = funcaoDaIntegral(Xn);

            }
            
        }

    }

}

void imprimeTabela(int n, double tabela[][n]){

    printf("\n\t\t\tTABELA\n");
    printf("\n  %14s  %14s  %14s  ", "n|", 
    "Xn|", "f(Xn)|");

    for(int linha = 0; linha <= n; linha++){
        printf("\n");
        for(int coluna = 0; coluna < 3; coluna++)printf(" %14.10lf|", tabela[linha][coluna]);
    }

}

void regraDosTrapezios(int n, double tabela[][n], double pontoA, double h){

    double resultado = 0;
    int contador = 0;
    int coluna = 0;
    int linha = 0;

    while(contador != n){

        resultado = (((h/2)*((tabela[contador][2]) + (tabela[contador + 1][2]))) + resultado);
        contador++;

    }

    printf("\n\nAproximacao Regra do Trapezio s = %.9lf +/- %.9lf\n\n", resultado, fabs(((pow(h, 3))/12) * funcao2derivada(pontoA)));

}

void regraDeSimpson(int n, double tabela[][n], double pontoA, double pontoB, double h){

    double resultado = 0;
    double resultado1 = 0;
    double In = 0;
    int contador1 = 1;
    int contador = 0;
    int coluna = 0;
    int linha = 0;

    while(contador != n){

        resultado = ((h/3)*((tabela[contador][2]) + (4*(tabela[contador1][2])) + (tabela[contador + 2][2]))) + resultado;
        contador1 = contador1 + 2;
        contador = contador + 2;

    }

    if(n % 4 == 0){

        contador = 0;
        contador1 = 2;
        h = (pontoB - pontoA)/(n/2);

        while(contador != n){

            resultado1 = ((h/3)*((tabela[contador][2]) + (4*(tabela[contador1][2])) + (tabela[contador + 4][2]))) + resultado1;
            contador1 = contador1 + 4;
            contador = contador + 4;

        }

        printf("\nAproximacao Regra de Simpson s = %.9lf +/- %.9lf\n\n", resultado, (fabs(resultado - resultado1)/15));

    }else{

        printf("\nAproximacao Regra de Simpson s = %.9lf\n\n", resultado);

    }

    system("pause");
    
}