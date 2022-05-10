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

    double pontoA = 0;              //Primeiro ponto do intervalo
    double pontoB = 0;              //Segundo ponto do intervalo
    double pontoInterv = 0;         //Ponto contido no intervalo
    double erro = 0;                //Erro maximo
    double funcaoDeA = 0;           //f(a)
    double funcaoDeB = 0;           //f(b)
    

    /*Equanto o produto entre f(a) e f(b) for maior ou igual a 0
    , repete o loop ate se digitar um intervalo valido*/
    while(funcaoDeA * funcaoDeB >= 0){

        system("cls");

        messagens(1); //Chamada funcao da menssagem 1
        scanf("%lf%lf", &pontoA, &pontoB);  //Scanei os pontos do usuario

        //Define funcao no ponto "a" e no ponto "b"
        funcaoDeA = ((atan(pontoA)) - (1/exp(pontoA)));
        funcaoDeB = ((atan(pontoB)) - (1/exp(pontoB)));

        /*Se o produto entre f(a) e f(b) eh menor que 0, logo o intervalo 
        eh valido*/
        if((funcaoDeA * funcaoDeB < 0)){
            
            /*Garante que o ponto esta fora do intervalo para poder entrar
            na condiçao while*/
            pontoInterv = pontoB + 1;

            //Equanto o pontoInterv estiver fora do intervalo
            while((pontoInterv > pontoB) || (pontoInterv < pontoA)){
                
                messagens(7);
                scanf("%lf", &pontoInterv); //Scanei um pontos do usuario

                //Se o pontoInterv estiver dentro do intervalo
                if((pontoInterv <= pontoB) && (pontoInterv >= pontoA)){
                    
                    messagens(9);
                    scanf("%lf", &erro); //Scanei o erro aceitavel

                    //Chamada de funcao dos metodos
                    metodoBissecao(pontoA, pontoB, erro);
                    metodoDasCordas(pontoA, pontoB, erro);
                
                }else{

                    system("cls");
                    messagens(8); //Chamada funcao da menssagem 2
                    system("pause");

                }
            
            }

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
    double funcaoDaSolucao;
    int contador = 0;

    system("cls");
    messagens(5);
    messagens(6);
    funcaoDeB = ((atan(posicaoB)) - (1/exp(posicaoB)));

    while(delta > desvio){

        funcaoDeA = ((atan(posicaoA)) - (1/exp(posicaoA)));
        solucao = posicaoA + ((funcaoDeA/(funcaoDeB - funcaoDeA)) * (posicaoA - posicaoB));
        funcaoDaSolucao = ((atan(solucao)) - (1/exp(solucao)));
        delta = fabs(posicaoA - solucao);

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        contador, posicaoA, solucao, funcaoDaSolucao, delta);
        printf("\n----------------------------------------------------------------------");

        posicaoA = solucao;
        contador++;

    }

    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", solucao, desvio);
    system("pause");

}

void fixaAVariaB(double posicaoA, double posicaoB, double desvio){

    double solucao;
    double delta = 1;
    double funcaoDeA;
    double funcaoDeB;
    double funcaoDaSolucao;
    int contador = 0;

    system("cls");
    messagens(5);
    messagens(6);
    funcaoDeA = ((atan(posicaoA)) - (1/exp(posicaoA)));

    while(delta > desvio){

        funcaoDeB = ((atan(posicaoB)) - (1/exp(posicaoB)));
        solucao = posicaoB + ((funcaoDeB/(funcaoDeA - funcaoDeB)) * (posicaoB - posicaoA));
        funcaoDaSolucao = ((atan(solucao)) - (1/exp(solucao)));
        delta = fabs(posicaoB - solucao);

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        contador, posicaoB, solucao, funcaoDaSolucao, delta);
        printf("\n----------------------------------------------------------------------");

        posicaoB = solucao;
        contador++;

    }


    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", solucao, delta);
    system("pause");

}

int messagens(int resposta){

    switch (resposta){

        case 1: printf("\n\nDigite o intervalo: ");
            break;

        case 2: printf("\n\nIntervalo invalido digitado\n");
            break;
        
        case 3: printf("\n\n\t\t\t\t\tMETODO BISSECAO\n");
            break;

        case 4: printf("\n  %2s   %13s   %13s   %13s   %13s   %13s   %13s  ", "n", 
                "a", "b", "m", "f(a)", "f(b)", "f(m)");
            printf("\n------------------------------------------------------------------------------------------------------");
            break;

        case 5: printf("\n\n\t\t\tMETODO DAS CORDAS\n");
            break;

        case 6: printf("\n  %2s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "Xn+1", "f(Xn+1)", "delta");
            printf("\n----------------------------------------------------------------------");
            break;

        case 7: printf("\n\nDigite um ponto no intervalo: ");
            break;

        case 8: printf("\n\nPonto fora do intervalo digitado\n");
            break;

        case 9: printf("\n\nDigite o erro aceitavel: ");
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

    system("cls");
    messagens(3);
    messagens(4);

    while(resultado != 1){

        pontoMedio = (parametroA + parametroB)/2;

        resultado = verificaPontoMedioEDelta(parametroA, parametroB, pontoMedio, epsilon);

        funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));
        funcaoDeB = ((atan(parametroB)) - (1/exp(parametroB)));
        funcaoDeM = ((atan(pontoMedio)) - (1/exp(pontoMedio)));

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        contador, parametroA, parametroB, pontoMedio, funcaoDeA, funcaoDeB, funcaoDeM);
        printf("\n------------------------------------------------------------------------------------------------------");

        if(resultado == 0){

            if((funcaoDeA * funcaoDeM) > 0){

                parametroA = pontoMedio;

            }else if((funcaoDeB * funcaoDeM) > 0){

                parametroB = pontoMedio;

            }


        }else{

            printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", pontoMedio, epsilon);
            system("pause");

        }

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