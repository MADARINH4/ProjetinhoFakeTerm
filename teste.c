#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

void metodoBissecao(double parametroA, double parametroB, double epsilon);
void metodoDasCordas(double parametroA, double parametroB, double epsilon);
int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);
void fixaBVariaA(double posicaoA, double posicaoB, double desvio);
void fixaAVariaB(double posicaoA, double posicaoB, double desvio);

int main(void){

    double verifica = 1;
    double pontoA = 0;
    double pontoB = 1;
    double erro = 0.0001;
    double funcaoDeA;
    double funcaoDeB;
    

    while(verifica > 0){

        system("cls");

        printf("\n\nDigite o intervalo: ");
        scanf("%lf%lf", &pontoA, &pontoB);

        funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
        funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));

        verifica = (funcaoDeA * funcaoDeB);

        if(verifica < 0){
            
            metodoBissecao(pontoA, pontoB, erro);
            metodoDasCordas(pontoA, pontoB, erro);

        }else{

            system("cls");
            printf("\n\nIntervalo invalido digitado\n");
            system("pause");


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

void fixaBVariaA(double posicaoA, double posicaoB, double desvio){

    double solucao;
    double delta = 1;
    double funcaoDeA;
    double funcaoDeB;

    funcaoDeB = ((atan(posicaoB)) - (1/exp(posicaoB)));

    while(delta > desvio){

        funcaoDeA = ((atan(posicaoA)) - (1/exp(posicaoA)));

        solucao = posicaoA + ((funcaoDeA/(funcaoDeB - funcaoDeA)) * (posicaoA - posicaoB));

        delta = fabs(posicaoA - solucao);

        posicaoA = solucao;

    }

    printf("\n\nsolucao eh: %.9lf\n", solucao);
    system("pause");
    system("cls");

}

void fixaAVariaB(double posicaoA, double posicaoB, double desvio){

    double solucao;
    double delta = 1;
    double funcaoDeA;
    double funcaoDeB;

    funcaoDeA = ((atan(posicaoA)) - (1/exp(posicaoA)));

    while(delta > desvio){

        funcaoDeB = ((atan(posicaoB)) - (1/exp(posicaoB)));

        solucao = posicaoB + ((funcaoDeB/(funcaoDeA - funcaoDeB)) * (posicaoB - posicaoA));

        delta = fabs(posicaoB - solucao);

        posicaoB = solucao;

    }

    printf("\n\nsolucao eh: %.9lf\n", solucao);
    system("pause");
    system("cls");

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

            printf("\n\nsolucao eh: %.9lf\n", pontoMedio);
            system("pause");
            system("cls");

        }

    }

}

void metodoDasCordas(double parametroA, double parametroB, double epsilon){

    double funcaoDeA;
    double derivada2DeA;

    funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));
    derivada2DeA = ((-2 * parametroA)/((1+parametroA*parametroA)*(1+parametroA*parametroA))) - (1/exp(parametroA));
    
    if((funcaoDeA * derivada2DeA) < 0){

        fixaBVariaA(parametroA, parametroB, epsilon);

    }else if((funcaoDeA * derivada2DeA) > 0){

        fixaAVariaB(parametroA, parametroB, epsilon);

    }   

}