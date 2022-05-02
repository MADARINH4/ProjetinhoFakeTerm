#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);

int main(void){

    int resultado = 1;
    double pontoA;
    double pontoB;
    double pontoMedio;
    double erro = 0.0001;

    resultado = resultado + 1;

    while(resultado != 1){

        pontoMedio = (pontoA + pontoB)/2;

        resultado = verificaPontoMedioEDelta(pontoA, pontoB, pontoMedio, erro);

        if(resultado == 0){

            double funcaoDeA;
            double funcaoDeB;
            double funcaoDeM;

            funcaoDeA = (atan(pontoA)) - (1/exp(pontoA));
            funcaoDeB = (atan(pontoB)) - (1/exp(pontoB));
            funcaoDeM = (atan(pontoMedio)) - (1/exp(pontoMedio));

            if((funcaoDeA * funcaoDeM) > 0){

                pontoA = pontoMedio;

            }else if((funcaoDeB * funcaoDeM) > 0){

                pontoB = pontoMedio;

            }


        }else{

            printf("solucao eh: %lf", pontoMedio);

        }

    }

    return 0;

}

int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon){

    double funcaoDeM;
    double delta;

    funcaoDeM = (atan(medio)) - (1/exp(medio));

    delta = abs(parametroB - parametroA);

    if(funcaoDeM == 0)return 1;
    if(delta < epsilon)return 1;

    return 0;

}