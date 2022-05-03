#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void metodoBissecao(double parametroA, double parametroB, double epsilon);
int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);

int main(void){

    double verifica = 1;
    double pontoA = 0;
    double pontoB = 1;
    double erro = 0.0001;
    double funcaoDeA;
    double funcaoDeB;
    

    while(verifica > 0){

        system("cls");

        printf("\nDigite o intervalo: ");
        scanf("%lf%lf", &pontoA, &pontoB);

        funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
        funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));

        verifica = (funcaoDeA * funcaoDeB);

        if(verifica < 0){
            
            metodoBissecao(pontoA, pontoB, erro);

        }

    }

    return 0;

}

int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon){

    double funcaoDeM;
    double delta;

    funcaoDeM = ((atan(medio)) - (1/exp(medio)));

    delta = fabs(parametroB - parametroA);

    if(funcaoDeM == 0)return 1;
    if(delta < epsilon)return 1;

    return 0;

}

void metodoBissecao(double parametroA, double parametroB, double epsilon){

    int resultado = 0;
    double pontoMedio;
    double funcaoDeA;
    double funcaoDeB;

    while(resultado != 1){

        pontoMedio = (parametroA + parametroB)/2;

        resultado = verificaPontoMedioEDelta(parametroA, parametroB, pontoMedio, epsilon);

        if(resultado == 0){

            double funcaoDeM;

            funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));
            funcaoDeB = ((atan(parametroB)) - (1/exp(parametroB)));
            funcaoDeM = ((atan(pontoMedio)) - (1/exp(pontoMedio)));

            if((funcaoDeA * funcaoDeM) > 0){

                parametroA = pontoMedio;

            }else if((funcaoDeB * funcaoDeM) > 0){

                parametroB = pontoMedio;

            }


        }else{

            printf("\n\nsolucao eh: %.9lf", pontoMedio);

        }

    }

}