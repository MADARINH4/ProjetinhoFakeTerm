#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//Funcao para o calculo atravez do metodo da bissacao
void metodoBissecao(double parametroA, double parametroB, double epsilon);

//Funcao para verificar se f(pontoMedio) = 0 ou se delta eh menor que o erro
int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon);

//Funcao para o calculo atravez do metodo das cordas
void metodoDasCordas(double parametroA, double parametroB, double epsilon);

//Funcao onde se aproxima da solucao pela esquerda, variando o ponto A
void fixaBVariaA(double posicaoA, double posicaoB, double desvio);

//Funcao onde se aproxima da solucao pela direita, variando o ponto B
void fixaAVariaB(double posicaoA, double posicaoB, double desvio);

//Funcao para o calculo atravez do metodo do ponto fixo
void metodoDoPontoFixo(double pontoB, double pontoDoInterv, double epsilon);

//Funcao para o calculo atravez do metodo de Newton Raphson
void metodoDeNewtonRaphson(double pontoB, double pontoDoInterv, double epsilon);

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
                    metodoDoPontoFixo(pontoB, pontoInterv, erro);
                    metodoDeNewtonRaphson(pontoB, pontoInterv, erro);
                
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

void metodoBissecao(double parametroA, double parametroB, double epsilon){

    int resultado = 0;           //Controla o loop principal da funcao
    double pontoMedio;           //Armazena o ponto medio
    double funcaoDeA;            //f(a)
    double funcaoDeB;            //f(b)
    double funcaoDeM;            //Funcao do ponto medio f(m)
    int L = 0;                   //Conta interacoes

    system("cls");               //Limpa a tela
    messagens(3);                //Chama funcao da menssagem 4
    messagens(4);

    //Enquanto resultado for diferente de 1, repete o loop
    while(resultado != 1){
        
        pontoMedio = (parametroA + parametroB)/2; //Calcula o ponto medio

        //Define o valor do resultado a parrtir do return da funcao verificaPontoMedioEDelta
        resultado = verificaPontoMedioEDelta(parametroA, parametroB, pontoMedio, epsilon);

        funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));  //Calcula o f(a)
        funcaoDeB = ((atan(parametroB)) - (1/exp(parametroB)));  //Calcula o f(b)   
        funcaoDeM = ((atan(pontoMedio)) - (1/exp(pontoMedio)));  //Calcula o f(m)

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, parametroA, parametroB, pontoMedio, funcaoDeA, funcaoDeB, funcaoDeM);
        printf("\n------------------------------------------------------------------------------------------------------");

        //Se resultado for extritamente igual a zero faça...
        if(resultado == 0){

            //Se (f(a) * f(m)) > 0 entao o novo parametroA eh definido como o pontoMedio
            if((funcaoDeA * funcaoDeM) > 0){

                parametroA = pontoMedio;

             //Se (f(b) * f(m)) > 0 entao o novo parametroB eh definido como o pontoMedio
            }else if((funcaoDeB * funcaoDeM) > 0){

                parametroB = pontoMedio;

            }


        }else{

            printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", pontoMedio, epsilon);
            system("pause");

        }

        L++;   //Incrermenta +1
        
    }

}

int verificaPontoMedioEDelta(double parametroA, double parametroB, double medio, double epsilon){

    double funcaoDeM;           //Funcao do ponto medio f(m)
    double delta;               //Armazena o erro calculado |b - a|

    funcaoDeM = ((atan(medio)) - (1/exp(medio)));   //Calcula o f(m)

    delta = fabs(parametroB - parametroA);          //Calcula o erro

    if(funcaoDeM == 0)return 1;     //Se f(m) for estritamente igual a 0, a funcao retorna 1
    if(delta < epsilon)return 1;    //Se delta calculado for menor que o erro dado, a funcao retorna 1

    return 0;   //Se nao satisfazer nenhuma das duas, a funcao retorna 0

}

void metodoDasCordas(double parametroA, double parametroB, double epsilon){

    double funcaoDeA;           //f(a)
    double derivada2DeA;        //Segunda deivada f"(a)

    funcaoDeA = ((atan(parametroA)) - (1/exp(parametroA)));     //Calcula o f(a)
    //Calcula o f"(a)
    derivada2DeA = ((-2 * parametroA)/((1+parametroA*parametroA)*(1+parametroA*parametroA))) - (1/exp(parametroA));
    
    //Se (f(a) * f"(a)) < 0, chama a fucao fixaBVariaA
    if((funcaoDeA * derivada2DeA) < 0){

        fixaBVariaA(parametroA, parametroB, epsilon);

     //Se (f(a) * f"(a)) > 0, chama a fucao fixaAVariaB   
    }else if((funcaoDeA * derivada2DeA) > 0){

        fixaAVariaB(parametroA, parametroB, epsilon);

    }

}

void fixaBVariaA(double posicaoA, double posicaoB, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    double funcaoDeXn;           //f(Xn)
    double funcaoDeB;            //f(b)
    double funcaoDeXnMaisUm;     //f(Xn+1)
    int L = 0;                   //Conta interacoes    

    //system("cls");               //Limpa a tela
    messagens(5);                //Chama funcao da menssagem 5
    messagens(6);

    //Calcula o f(b) que é fixo
    funcaoDeB = ((atan(posicaoB)) - (1/exp(posicaoB)));
    Xn = posicaoA;               //Define Xn como ponto A que irá variar
    delta = epsilon + 1;         //Garante o delta maior que o erro

    //Enquanto delta maior que o erro dado, repete o loop
    while(delta >= epsilon){

        funcaoDeXn = ((atan(Xn)) - (1/exp(Xn)));    //Calcula o f(Xn)
        //Calcula o Xn+1 atravez da formula
        XnMaisUm = Xn + ((funcaoDeXn/(funcaoDeB - funcaoDeXn)) * (Xn - posicaoB));
        //Calcula o f(Xn+1)
        funcaoDeXnMaisUm = ((atan(XnMaisUm)) - (1/exp(XnMaisUm)));
        //Define o delta como |Xn - Xn+1|
        delta = fabs(Xn - XnMaisUm);

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, posicaoA, XnMaisUm, funcaoDeXnMaisUm, delta);
        printf("\n----------------------------------------------------------------------");

        Xn = XnMaisUm;           //Xn passa a ser Xn+1 anterior
        L++;                     //Incrementa +1

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, epsilon);
    system("pause");

}

void fixaAVariaB(double posicaoA, double posicaoB, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    double funcaoDeA;            //f(a)
    double funcaoDeXn;           //f(Xn)
    double funcaoDeXnMaisUm;     //f(Xn+1)
    int L = 0;                   //Conta interacoes

    //system("cls");               //Limpa a tela
    messagens(5);                //Chama funcao da menssagem 5
    messagens(6);

    //Calcula o f(a) que é fixo
    funcaoDeA = ((atan(posicaoA)) - (1/exp(posicaoA)));
    Xn = posicaoB;               //Define Xn como ponto B que irá variar
    delta = epsilon + 1;         //Garante o delta maior que o erro

    //Enquanto delta maior que o erro dado, repete o loop
    while(delta >= epsilon){

        funcaoDeXn = ((atan(Xn)) - (1/exp(Xn)));   //Calcula o f(Xn)
        //Calcula o Xn+1 atravez da formula
        XnMaisUm = Xn + ((funcaoDeXn/(funcaoDeA - funcaoDeXn)) * (Xn - posicaoA));
        //Calcula o f(Xn+1)
        funcaoDeXnMaisUm = ((atan(XnMaisUm)) - (1/exp(XnMaisUm)));
        //Define o delta como |Xn - Xn+1|
        delta = fabs(Xn - XnMaisUm);

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, XnMaisUm, funcaoDeXnMaisUm, delta);
        printf("\n----------------------------------------------------------------------");

        Xn = XnMaisUm;           //Xn passa a ser Xn+1 anterior
        L++;                     //Incrementa +1

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, delta);
    system("pause");

}

void metodoDoPontoFixo(double pontoB, double pontoDoInterv, double epsilon){

    double Xn;              //Primeiro valor a ser ultilizado
    double XnMaisUm;        //Proximo valor
    double funcaoDeX;       //Funcao principal
    double funcaoGdeX;      //Funcao g(x)
    int L = 0;              //Conta interacoes

    XnMaisUm = pontoB + 1;  //garante que Xn+1 - Xn sera maior que epsilon
    Xn = pontoDoInterv;     //define Xn como o ponto digitado do intervalo
    messagens(10);
    messagens(11);

    //Enquanto o |Xn+1 - Xn| for maior ou igual ao erro, repete o loop
    while(((fabs(XnMaisUm - Xn)) >= epsilon)){
        
        //Nao define a Xn igual XnMaisUm na primera rodada
        if(L != 0 )Xn = XnMaisUm;

        //Calcula g(Xn) sempre com o anterior a Xn+1
        funcaoGdeX = tan((1/(exp(Xn))));
        //Calcula f(Xn) sempre com o anterior a Xn+1
        funcaoDeX = ((atan(Xn)) - (1/exp(Xn)));
        XnMaisUm = funcaoGdeX;  //Define o XnMaisUm igual ao g(Xn)
        
        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, funcaoGdeX, XnMaisUm, funcaoDeX);
        printf("\n----------------------------------------------------------------------");

        L++; //Incrementa +1 sempre que rodar o loop

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, (fabs(XnMaisUm - Xn)));
    system("pause");

}

void metodoDeNewtonRaphson(double pontoB, double pontoDoInterv, double epsilon){

    double Xn;              //Primeiro valor a ser ultilizado
    double XnMaisUm;        //Proximo valor
    double funcaoDeX;       //Funcao principal
    double derivadaDeX;     //Derivada da Funcao, f'(x)
    int L = 0;              //Conta interacoes

    XnMaisUm = pontoB + 1;  //define Xn+1 fora do intervalo, garante que entre no loop
    Xn = pontoDoInterv;     //define Xn como o ponto digitado do intervalo
    messagens(12);
    messagens(13);

    //Enquanto o |Xn+1 - Xn| for maior ou igual ao erro, repete o loop
    while(((fabs((XnMaisUm - Xn))) >= epsilon)){
        
        //Nao define a Xn igual XnMaisUm na primera rodada
        if(L != 0 )Xn = XnMaisUm;

        //Calcula f(Xn) sempre com o anterior a Xn+1
        funcaoDeX = ((atan(Xn)) - (1/exp(Xn)));
        //Calcula f'(Xn) sempre com o anterior a Xn+1
        derivadaDeX = ((1/(1 + (Xn * Xn))) + (1/exp(Xn)));
        XnMaisUm = (Xn - (funcaoDeX/derivadaDeX));  //Define o XnMaisUm igual ao g(Xn)
        
        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, funcaoDeX, XnMaisUm, derivadaDeX);
        printf("\n----------------------------------------------------------------------");

        L++; //Incrementa +1 sempre que rodar o loop

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, (fabs((XnMaisUm - Xn))));
    system("pause");

}

int messagens(int resposta){

    /*"resposta" recebe o valor na chamada da funcao, e de acordo com esse valor 
    define qual o caso no switch*/
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

        case 10: printf("\n\n\t\t\tMETODO DO PONTO FIXO\n");
            break;

        case 11: printf("\n  %2s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "g(Xn)", "Xn+1", "f(Xn)");
            printf("\n----------------------------------------------------------------------");
            break;

        case 12: printf("\n\n\t\t\tMETODO DE NEWTON RAPHSON\n");
            break;

        case 13: printf("\n  %2s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "f(Xn)", "Xn+1", "f'(Xn)");
            printf("\n----------------------------------------------------------------------");
            break;                     
    
        default:
            break;
    }

}
