#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//void metodoBissecao(double parametroA, double parametroB, double medio, double epsilon);
int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);

int main(void){

    double verifica = 1;
    int resultado = 1;
    double pontoA = 0;
    double pontoB = 1;
    double pontoMedio;
    double erro = 0.0001;
    double funcaoDeA;
    double funcaoDeB;
    

    while(verifica > 0){

        printf("\nDigite o intervalo: ");
        scanf("%lf%lf", &pontoA, &pontoB);

        funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
        funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));

        printf("\n\nverifica eh: %.9lf.......%.9lf", funcaoDeA, funcaoDeB);

        verifica = (funcaoDeA * funcaoDeB);

        //printf("\n\nverifica eh: %.9lf", verifica);

        if(verifica < 0){

            while(resultado != 1){

                pontoMedio = (pontoA + pontoB)/2;

                resultado = verificaPontoMedioEDelta(pontoA, pontoB, pontoMedio, erro);

                if(resultado == 0){

                    double funcaoDeM;

                    funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
                    funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));
                    funcaoDeM = ((atan(pontoMedio)) - (1/exp(pontoMedio)));

                    if((funcaoDeA * funcaoDeM) > 0){

                        pontoA = pontoMedio;

                    }else if((funcaoDeB * funcaoDeM) > 0){

                        pontoB = pontoMedio;

                    }


                }else{

                    printf("\n\nsolucao eh: %.9lf", pontoMedio);

                }

            }

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