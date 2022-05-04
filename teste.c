#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//Funcao para o calculo atravez do metodo da bissacao
void metodoBissecao(double parametroA, double parametroB, double epsilon);

//Funcao para o calculo atravez do metodo das cordas
void metodoDasCordas(double parametroA, double parametroB, double epsilon);

//Funcao para verificar se f(pontoMedio) = 0 ou se delta eh menoor que o erro
int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);

//Funcao onde se aproxima da solucao pela esquerda, variando o ponto A
void fixaBVariaA(double posicaoA, double posicaoB, double desvio);

//Funcao onde se aproxima da solucao pela direita, variando o ponto B
void fixaAVariaB(double posicaoA, double posicaoB, double desvio);

//Armazena mensagens para impressao
int messagens(int resposta);

int main(void){

    double verifica = 1;            //Controla o loop principal
    double pontoA = 0;              //Primeiro ponto do iintervalo
    double pontoB = 1;              //Segundo ponto do iintervalo
    double erro = 0.0001;           //Erro maximo
    double funcaoDeA;               //f(a)
    double funcaoDeB;               //f(b)
    

    /*Equanto o produto entre f(a) e f(b) for maior que 0
    , repete o loop ate se digitar um intervalo valido*/
    while(verifica > 0){

        system("cls");

        messagens(1); //Chamada funcao da menssagem 1

        //Scanei os pontos do usuario
        scanf("%lf%lf", &pontoA, &pontoB);

        //Define funcao no ponto "a" e no ponto "b"
        funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
        funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));

        //Calcula valor do produto entre as funcaoes
        verifica = (funcaoDeA * funcaoDeB);

        /*Se "verifica" menor que 0, entao o produto entre
        f(a) e f(b) eh menor que 0, logo o intervalo eh
        valido*/
        if(verifica < 0){
            
            //Chamada de funcao dos metodos
            metodoBissecao(pontoA, pontoB, erro);
            metodoDasCordas(pontoA, pontoB, erro);

        }else{

            system("cls");
            messagens(2); //Chamada funcao da menssagem 2
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

    system("cls");
    printf("\n\nsolucao eh: %.9lf\n", solucao);
    system("pause");

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

    system("cls");
    printf("\n\nsolucao eh: %.9lf\n", solucao);
    system("pause");

}

int messagens(int resposta){

    switch (resposta){

        case 1:

            printf("\n\nDigite o intervalo: ");
            break;

        case 2:

            printf("\n\nIntervalo invalido digitado\n");
            break;
        
        case 3:

            printf("\n\nIntervalo invalido digitado\n");
            break;        
    
        default:
            break;
    }

}

void metodoBissecao(double parametroA, double parametroB, double epsilon){

    int resultado = 0;
    double pontoMedio;
    double funcaoDeA;
    double funcaoDeB;
    double funcaoDeM;
    int contador = 0;

    while(resultado != 1){

        pontoMedio = (parametroA + parametroB)/2;

        resultado = verificaPontoMedioEDelta(parametroA, parametroB, pontoMedio, epsilon);

        if(resultado == 0){

            funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));
            funcaoDeB = ((atan(parametroB)) - (1/exp(parametroB)));
            funcaoDeM = ((atan(pontoMedio)) - (1/exp(pontoMedio)));

            if((funcaoDeA * funcaoDeM) > 0){

                parametroA = pontoMedio;

            }else if((funcaoDeB * funcaoDeM) > 0){

                parametroB = pontoMedio;

            }


        }else{

            //system("cls");
            printf("\n\nsolucao eh: %.9lf\n", pontoMedio);
            system("pause");

        }

        printf("\n\n%13d%13.9lf%13.9lf%13.9lf%13.9lf%13.9lf%13.9lf", 
        contador, parametroA, parametroB, pontoMedio, funcaoDeA, funcaoDeB, funcaoDeM);
        contador++;

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