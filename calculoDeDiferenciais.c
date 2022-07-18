#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Fxy(double Xn, double Yn);
double FxyOriginal(double Xn);
void metodoEuler(double n, double h, double Xn, double Yn);
void metodoRungeKutta2(double n, double h, double Xn, double Yn);
void metodoRungeKutta3(double n, double h, double Xn, double Yn);
void metodoRungeKutta4(double n, double h, double Xn, double Yn);

int main(void){

    double Xn, Yn, h, Xresultado, n;

    system("cls");

    printf("\n\nDigite os pontos iniciais (x, y): ");
    scanf("%lf%lf", &Xn, &Yn);
    printf("\nDigite o valor de h: ");
    scanf("%lf", &h);
    printf("\nDigite o ponto a ser calculado na funcao y(?): ");
    scanf("%lf", &Xresultado);

    //Define o numero de repetições parar as funções
    n = (Xresultado - Xn)/h;
    system("cls");

    metodoEuler(n, h, Xn, Yn);
    metodoRungeKutta2(n, h, Xn, Yn);
    metodoRungeKutta3(n, h, Xn, Yn);
    metodoRungeKutta4(n, h, Xn, Yn);

    return 0;

}

double Fxy(double Xn, double Yn){

    return (pow(Xn, 2) - (Yn/Xn));

}

double FxyOriginal(double Xn){

    return ((pow(Xn, 4) + 3)/(4*Xn));

}

void metodoEuler(double n, double h, double Xn, double Yn){

    double XnMaisUm, YnMaisUm;
    int contador = 0;

    printf("\n\n\t        METODO DE EULER\n");
    printf("\n  %3s   %13s   %13s   %13s  ", "n", 
    "Xn", "Yn", "f(x, y)");
    printf("\n-------------------------------------------------------");

    while(contador <= n){

        if(contador != n){

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, Fxy(Xn, Yn));
            printf("\n-------------------------------------------------------");

        }
        else{

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, (Fxy(Xn, Yn) - Fxy(Xn, Yn)));
            printf("\n-------------------------------------------------------");

        }

        if(contador != n){

            XnMaisUm = Xn + h;
            YnMaisUm = Yn + (h * Fxy(Xn, Yn));
            Xn = XnMaisUm;
            Yn = YnMaisUm;
        
        }

        contador++;

    }
    
    printf("\n\nResultado aproximado: y(%lf) = %.9lf", Xn, Yn);
    printf("\nErro Absoluto: Eab = %.9lf\n", fabs(Yn - FxyOriginal(Xn)));


    system("pause");

}

void metodoRungeKutta2(double n, double h, double Xn, double Yn){

    double XnMaisUm, YnMaisUm, K1, K2;
    int contador = 0;

    K1 = h*Fxy(Xn, Yn);
    K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));

    printf("\n\n\t\t      METODO DE RUNGE-KUTTA 2\n");
    printf("\n  %3s   %13s   %13s   %13s  %13s  ", "n", 
    "Xn", "Yn", "K1", "K2");
    printf("\n-----------------------------------------------------------------------");

    while(contador <= n){

        if(contador != n){

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1, K2);
            printf("\n-----------------------------------------------------------------------");

        }
        else{

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1 - K1, K2 - K2);
            printf("\n-----------------------------------------------------------------------");

        }

        if(contador != n){

            XnMaisUm = Xn + h;
            YnMaisUm = Yn + ((K1 + K2)/2);
            Xn = XnMaisUm;
            Yn = YnMaisUm;
            K1 = h*Fxy(Xn, Yn);
            K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));
        
        }

        contador++;

    }
    
    printf("\n\nResultado aproximado: y(%lf) = %.9lf", Xn, Yn);
    printf("\nErro Absoluto: Eab = %.9lf\n", fabs(Yn - FxyOriginal(Xn)));


    system("pause");

}

void metodoRungeKutta3(double n, double h, double Xn, double Yn){

    double XnMaisUm, YnMaisUm, K1, K2, K3;
    int contador = 0;

    K1 = h*Fxy(Xn, Yn);
    K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));
    K3 = h*Fxy(Xn + h, (Yn - K1 + (2*K2)));

    printf("\n\n\t\t\t      METODO DE RUNGE-KUTTA 3\n");
    printf("\n  %3s   %13s   %13s   %13s  %13s  %13s  ", "n", 
    "Xn", "Yn", "K1", "K2", "K3");
    printf("\n---------------------------------------------------------------------------------------");

    while(contador <= n){

        if(contador != n){

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1, K2, K3);
            printf("\n---------------------------------------------------------------------------------------");

        }
        else{

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1 - K1, K2 - K2, K3 - K3);
            printf("\n---------------------------------------------------------------------------------------");

        }

        if(contador != n){

            XnMaisUm = Xn + h;
            YnMaisUm = Yn + ((K1 + (4*K2) + K3)/6);
            Xn = XnMaisUm;
            Yn = YnMaisUm;
            K1 = h*Fxy(Xn, Yn);
            K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));
            K3 = h*Fxy(Xn + h, (Yn - K1 + (2*K2)));
        
        }

        contador++;

    }
    
    printf("\n\nResultado aproximado: y(%lf) = %.9lf", Xn, Yn);
    printf("\nErro Absoluto: Eab = %.9lf\n", fabs(Yn - FxyOriginal(Xn)));

    system("pause");

}

void metodoRungeKutta4(double n, double h, double Xn, double Yn){

    double XnMaisUm, YnMaisUm, K1, K2, K3, K4;
    int contador = 0;

    K1 = h*Fxy(Xn, Yn);
    K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));
    K3 = h*Fxy(Xn + (h/2), Yn + (K2/2));
    K4 = h*Fxy(Xn + h, Yn + K3);

    printf("\n\n\t\t\t\t      METODO DE RUNGE-KUTTA 4\n");
    printf("\n  %3s   %13s   %13s   %13s  %13s  %13s  %13s ", "n", 
    "Xn", "Yn", "K1", "K2", "K3", "K4");
    printf("\n-------------------------------------------------------------------------------------------------------");

    while(contador <= n){

        if(contador != n){

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1, K2, K3, K4);
            printf("\n-------------------------------------------------------------------------------------------------------");

        }
        else{

            printf("\n| %3d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
            contador, Xn, Yn, K1 - K1, K2 - K2, K3 - K3, K4 - K4);
            printf("\n-------------------------------------------------------------------------------------------------------");

        }

        if(contador != n){

            XnMaisUm = Xn + h;
            YnMaisUm = Yn + ((K1 + (2*K2) + (2*K3) + K4)/6);
            Xn = XnMaisUm;
            Yn = YnMaisUm;
            K1 = h*Fxy(Xn, Yn);
            K2 = h*Fxy(Xn + (h/2), Yn + (K1/2));
            K3 = h*Fxy(Xn + (h/2), Yn + (K2/2));
            K4 = h*Fxy(Xn + h, Yn + K3);
        
        }

        contador++;

    }
    
    printf("\n\nResultado aproximado: y(%lf) = %.9lf", Xn, Yn);
    printf("\nErro Absoluto: Eab = %.9lf\n", fabs(Yn - FxyOriginal(Xn)));


    system("pause");

}