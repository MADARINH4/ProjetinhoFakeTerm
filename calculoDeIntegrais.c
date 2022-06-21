#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

double funcaoDaIntegral(double X);
double funcao2derivada(double X);
void regraDosTrapezios(double pontoA, double pontoB, double n);

int main(void){

    double pontoA = 0;
    double pontoB = 0;
    double n = 0;
    bool loop = true;
    char resposta;

    system("cls");
    printf("\n\n\tPontos do intervalo. Ex: 1 2. Digite: ");
    scanf("%lf%lf", &pontoA, &pontoB);
    system("cls");
    printf("\n\n\tQuantas particoes no intervalo: ");
    scanf("%lf", &n);
    system("cls");

    while(loop){

        while(!isalpha(resposta)){
            
            printf("\n\n\t==============================   \n");
            printf("\t      CALCULA INTEGRAIS         \n");
            printf("\t============================== \n\n");

            printf("\t Enter [T] -> Regra Trapezio\n");
            printf("\t Enter [S] -> Regra Simpson\n");
            printf("\t Enter [E] -> Sair\n\n");
        
            printf("\t==============================   \n");
        
            printf("\tPor favor Enter sua escolha: ");
            
            scanf("%1c", &resposta);
            resposta = tolower(resposta); //deixa qualquer letra minuscula

            if((resposta != 't')&&(resposta != 's')&&(resposta != 'e'))resposta = '0';
        
            system("cls");

        }
        
        switch (resposta){
            
            case 't':

                regraDosTrapezios(pontoA, pontoB, n);
                resposta = '0';
                break;

            case 's':

                resposta = '0';
                break;

            case 'e':

                return 0;

        }

    }  

    return 0;

}

double funcaoDaIntegral(double X){

    return ((4*pow(X, 5)) - 1)/((pow(X, 10)) + 2*(pow(X, 6)) + 2*(pow(X, 5)) + (pow(X, 2)) + (2*X) + 1);

}

double funcao2derivada(double X){

    return (6*((20*pow(X, 13)) - (40*pow(X, 9)) - (85*pow(X, 8)) + (4*pow(X, 5)) + (10*pow(X, 4)) + (20*pow(X, 3)) - 1))/ pow((pow(X, 5) + X + 1), 4);

}

void regraDosTrapezios(double pontoA, double pontoB, double n){

    double h = 0;
    double Xn = 0;
    double XnMaisUm = 0;
    double resultado = 0;
    int contador = 0;

    h = (pontoB - pontoA)/n;

    printf("\n\n\t\t\t\tRegra Dos Trapezios Composta\n");
    printf("\n\t  %2s   %13s   %13s   %13s   %13s  ", "n", 
    "Xn", "Xn+1", "f(Xn)", "f(Xn+1)");

    while(contador != n){

        Xn = (pontoA + (contador*h));
        XnMaisUm = (pontoA + ((contador + 1)*h));

        resultado = ((h/2)*(funcaoDaIntegral(Xn) + funcaoDaIntegral(XnMaisUm))) + resultado;
        
        printf("\n\t| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
        contador, Xn, XnMaisUm, funcaoDaIntegral(Xn), funcaoDaIntegral(XnMaisUm));

        contador++;

    }

    printf("\n\n\tAproximacao s = %.9lf\n", resultado);
    system("pause");

}