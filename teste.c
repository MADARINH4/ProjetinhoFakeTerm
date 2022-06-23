#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

double funcaoDaIntegral(double X);
double funcao2derivada(double X);
void preencheTabela(int slot, double tabela[][slot], double pontoA, double h);
int menu(int slot, double tabela[][slot], double h);
//void regraDosTrapezios(int slot, double tabela[][slot], double h);
void regraDeSimpson(int slot, double tabela[][slot], double h);

int main(void){

    double pontoA = 0;
    double pontoB = 0;
    double n = 0;
    double h = 0;
    int slot = 0;
    bool loop = true;
    char resposta;

    system("cls");
    printf("\n\n\tPontos do intervalo. Ex: 1 2. Digite: ");
    scanf("%lf%lf", &pontoA, &pontoB);
    system("cls");
    printf("\n\n\tQuantas particoes no intervalo: ");
    scanf("%lf", &n);
    system("cls");

    h = (pontoB - pontoA)/n;
    slot = n;

    double tabela[slot][slot];

    preencheTabela(slot, tabela, pontoA, h);


    while(loop){

        if(menu(slot, tabela, h) == 0){

            return 0;

        }else{

            menu(slot, tabela, h);

        }

    }

    return 0;

}

double funcaoDaIntegral(double X){

    return exp(X)/(1 + exp(2*X));

}

double funcao2derivada(double X){

    return (6*((20*pow(X, 13)) - (40*pow(X, 9)) - (85*pow(X, 8)) + (4*pow(X, 5)) + (10*pow(X, 4)) + (20*pow(X, 3)) - 1))/ pow((pow(X, 5) + X + 1), 4);

}

void preencheTabela(int slot, double tabela[][slot], double pontoA, double h){

    int coluna;
    int linha;
    double Xn = 0;

    for(coluna = 0; coluna < 3; coluna++){

        for(linha = 0; linha <= slot; linha++){

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

int menu(int slot, double tabela[][slot], double h){

    char resposta;

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

            //regraDosTrapezios(slot, tabela, h);
            resposta = '0';
            return 1;

        case 's':

            if(slot % 2 == 0){

                regraDeSimpson(slot, tabela, h);

            }else{

                printf("\n\n\tNumero de particoes invalido para esta regra\n");
                system("pause");

            }

            resposta = '0';
            return 1;

        case 'e':

            return 0;

    } 

}

/*void regraDosTrapezios(double pontoA, double pontoB, double n){

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

}*/

void regraDeSimpson(int slot, double tabela[][slot], double h){

    double resultado = 0;
    double In = 0;
    int contador1 = 1;
    int contador = 0;
    int coluna = 0;
    int linha = 0;

    for(linha = 0; linha <= slot; linha++){
        printf("\n");
        for(coluna = 0; coluna < 3; coluna++)printf(" %14.10lf|", tabela[linha][coluna]);
    }

    printf("\n\n");

    while(contador != slot){

        resultado = ((h/3)*((tabela[contador][2]) + (4*(tabela[contador1][2])) + (tabela[contador + 2][2]))) + resultado;
        
        if(contador == slot/2)In = resultado;

        contador1 = contador1 + 2;
        contador = contador + 2;

    }

    printf("\n\n\tAproximacao s = %.9lf +/- %.9lf\n", resultado, In);
    system("pause");
    
}