#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void defineXeF(int n, double tabela[][n]);
void calculaDiferencaDivida(int n, double tabela[][n]);
void imprimeTabela(int n, double tabela[][n]);

int main(void){

    int n = 0;              //Numero de valores conhecidos de x

    system("cls");
    printf("\n\n Digite o numeros de valores conhecidos de x: ");
    scanf("%d", &n);
    
    n = n + 2;              //Adiciona mais 2 para a tabela

    double tabela[n][n];

    system("cls");
    defineXeF(n, tabela);
    calculaDiferencaDivida(n, tabela);
    system("cls");
    imprimeTabela(n, tabela);
    system("pause");

    return 0;

}

void defineXeF(int n, double tabela[][n]){

    for(int coluna = 0; coluna < 2; coluna++){

        if(coluna == 0){

            system("cls");
            printf("\n\n Digite os valores de x!\n");
            for(int linha = 0; linha < n-2; linha++)scanf("%lf", &tabela[linha][coluna]);
            
        }else{

            system("cls");
            printf("\n\n Digite os valores de f(x)!\n");
            for(int linha = 0; linha < n-2; linha++)scanf("%lf", &tabela[linha][coluna]);


        }

    }

}

void calculaDiferencaDivida(int n, double tabela[][n]){

    for(int coluna = 2; coluna < n; coluna++){

        for(int linha = 0; linha < ((n - 1) - (coluna - 1)); linha++){

            tabela[linha][coluna] = (((tabela[linha + 1][coluna - 1]) - (tabela[linha][coluna - 1]))/ ((tabela[linha + (coluna -1)][0]) - (tabela[linha][0])));

        }

    }

}

void imprimeTabela(int n, double tabela[][n]){

    int linha;
    int coluna = 0;

    for(linha = 0; linha < (n - 2); linha++){

        printf("\n");

        if(linha == 0){

            while(coluna < n - 1){

                if(coluna == 0)printf(" %14s|", "X");
                if(coluna == 1)printf(" %14s|", "F(x)");
                if(coluna > 1)printf("%14s%d|", "DeltaF", coluna - 1);
                coluna++;

            }
            
            printf("\n");

        }

        if(linha != (n - 2))for(coluna = 0; coluna < (n - (linha + 1)); coluna++)printf(" %14.10lf|", tabela[linha][coluna]);
        else for(coluna = 0; coluna < (n - (linha)); coluna++)printf(" %14.10f|", tabela[linha][coluna]);

    }

    printf("\n\n");

}
