#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Armazena funcaos
double funcaoPrincipal(double Xn);
double funcaoDerivada(double Xn);
double funcao2Derivada(double Xn);
double funcaoInteracao(double Xn);

//Funcao para o calculo atravez do metodo da bissacao
void metodoBissecao(double pontoA, double pontoB, double epsilon);

//Funcao para o calculo atravez do metodo das cordas
void metodoDasCordas(double pontoA, double pontoB, double epsilon);

//Funcao onde se aproxima da solucao fixando B e variando A
void fixaBVariaA(double posicaoA, double posicaoB, double desvio);

//Funcao onde se aproxima da solucao fixando A e variando B
void fixaAVariaB(double posicaoA, double posicaoB, double desvio);

//Funcao para o calculo atravez do metodo do ponto fixo
void metodoDoPontoFixo(double pontoDoInterv, double epsilon);

//Funcao para o calculo atravez do metodo de Newton Raphson
void metodoDeNewtonRaphson(double pontoDoInterv, double epsilon);

//Armazena mensagens para impressao
void messagens(int resposta);

int main(void){

    double pontoA = 0;              //Primeiro ponto do intervalo
    double pontoB = 0;              //Segundo ponto do intervalo
    double pontoInterv = 0;         //Ponto contido no intervalo
    double tolerancia = 0;          //Tolerancia maximo
    
    /*Equanto o produto entre f(a) e f(b) for maior ou igual a 0
    , repete o loop ate se digitar um intervalo valido*/
    while(funcaoPrincipal(pontoA) * funcaoPrincipal(pontoB) >= 0){

        system("cls");

        messagens(1); //Chamada funcao da menssagem 1
        scanf("%lf%lf", &pontoA, &pontoB);  //Scanei os pontos do usuario

        /*Se o produto entre f(a) e f(b) eh menor que 0, logo o intervalo 
        eh valido*/
        if((funcaoPrincipal(pontoA) * funcaoPrincipal(pontoB) < 0)){
            
            /*Garante que o ponto esta fora do intervalo para poder entrar
            na condiçao while*/
            pontoInterv = pontoB + 1;

            //Equanto o pontoInterv estiver fora do intervalo
            while((pontoInterv > pontoB) || (pontoInterv < pontoA)){
                
                messagens(7);
                scanf("%lf", &pontoInterv); //Scanei um pontos do usuario

                //Se o pontoInterv estiver dentro do intervalo
                if((pontoInterv <= pontoB) && (pontoInterv >= pontoA)){
                    
                    //Enquanto o erro não for entre 0 e 1
                    while((tolerancia <= 0) || (tolerancia >= 1)){
                        
                        messagens(9);
                        scanf("%lf", &tolerancia); //Scanei um pontos do usuario
                        
                        //Se o erro estiver entre 0 e 1
                        if((tolerancia > 0) && (tolerancia < 1)){

                            //Chamada de funcao dos metodos
                            metodoBissecao(pontoA, pontoB, tolerancia);
                            metodoDasCordas(pontoA, pontoB, tolerancia);
                            metodoDoPontoFixo(pontoInterv, tolerancia);
                            metodoDeNewtonRaphson(pontoInterv, tolerancia);
                        
                        }else{

                            system("cls");
                            messagens(14); //Chamada funcao da menssagem 14
                            system("pause");
                            system("cls");

                        }
                    
                    }
                
                }else{

                    system("cls");
                    messagens(8); //Chamada funcao da menssagem 8
                    system("pause");
                    system("cls");

                }
            
            }

        }else{

            system("cls");
            messagens(2); //Chamada funcao da menssagem 2
            system("pause");
            system("cls");

        }

    }

    return 0;

}

double funcaoPrincipal(double Xn){

    return ((atan(Xn)) - (1/exp(Xn)));

}
double funcaoDerivada(double Xn){

    return ((1/(1 + (Xn * Xn))) + (1/exp(Xn)));

}
double funcao2Derivada(double Xn){

    return ((-2 * Xn)/((1+Xn*Xn)*(1+Xn*Xn))) - (1/exp(Xn));

}
double funcaoInteracao(double Xn){

    return tan((1/(exp(Xn))));

}

void metodoBissecao(double pontoA, double pontoB, double epsilon){

    double pontoMedio;           //Armazena o ponto medio
    double delta;                //Armazena o erro calculado |b - a|
    int L = 0;                   //Conta interacoes

    delta = epsilon;             //Garante que entre no loop
    system("cls");               //Limpa a tela
    messagens(3);                //Chama funcao da menssagem 4
    messagens(4);
    
    //Enquanto o delta for maior ou igual a tolerancia...
    while((delta >= epsilon)){
        
        pontoMedio = (pontoA + pontoB)/2; //Calcula o ponto medio
        delta = fabs(pontoB - pontoA);    //Calcula o |b - a|

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, pontoA, pontoB, pontoMedio, funcaoPrincipal(pontoA), funcaoPrincipal(pontoB), funcaoPrincipal(pontoMedio), delta);
        printf("\n----------------------------------------------------------------------------------------------------------------------");

        //Se (f(a) * f(m)) > 0 entao o novo pontoA eh definido como o pontoMedio
        if((funcaoPrincipal(pontoA) * funcaoPrincipal(pontoMedio)) > 0){

            pontoA = pontoMedio;

        //Se (f(b) * f(m)) > 0 entao o novo pontoB eh definido como o pontoMedio
        }else if((funcaoPrincipal(pontoB) * funcaoPrincipal(pontoMedio)) > 0){

            pontoB = pontoMedio;

        }
        //Se delta for menor que a tolerancia
        if((delta < epsilon)){

            printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", pontoMedio, delta);
            system("pause");

        }

        L++;   //Incrermenta +1
        
    }

}

void metodoDasCordas(double pontoA, double pontoB, double epsilon){
    
    //Se (f(a) * f"(a)) < 0, chama a fucao fixaBVariaA
    if((funcaoPrincipal(pontoA) * funcao2Derivada(pontoA)) < 0){

        fixaBVariaA(pontoA, pontoB, epsilon);

     //Se (f(a) * f"(a)) > 0, chama a fucao fixaAVariaB
    }else if(funcaoPrincipal(pontoA) * funcao2Derivada(pontoA) > 0){

        fixaAVariaB(pontoA, pontoB, epsilon);

    }

}

void fixaBVariaA(double pontoA, double pontoB, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    int L = 0;                   //Conta interacoes    

    messagens(5);                //Chama funcao da menssagem 5
    messagens(6);

    Xn = pontoA;                 //Define Xn como pontoA
    delta = epsilon + 1;         //Garante o delta maior que o erro

    //Enquanto delta maior ou igual a tolerancia, repete o loop
    while(delta >= epsilon){

        //Calcula o Xn + 1
        XnMaisUm = Xn + ((funcaoPrincipal(Xn)/(funcaoPrincipal(pontoB) - funcaoPrincipal(Xn))) * (Xn - pontoB));
        delta = fabs(Xn - XnMaisUm);  //Define o delta como |Xn - Xn+1|

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, funcaoPrincipal(Xn), XnMaisUm, delta);
        printf("\n----------------------------------------------------------------------");

        Xn = XnMaisUm;           //Xn passa a ser Xn+1 anterior
        L++;                     //Incrementa +1

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, delta);
    system("pause");

}

void fixaAVariaB(double pontoA, double pontoB, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    int L = 0;                   //Conta interacoes    

    messagens(5);                //Chama funcao da menssagem 5
    messagens(6);

    Xn = pontoB;                 //Define Xn como pontoB
    delta = epsilon + 1;         //Garante o delta maior que o erro

    //Enquanto delta maior ou igual a tolerancia, repete o loop
    while(delta >= epsilon){

        //Calcula o Xn + 1
        XnMaisUm = Xn + ((funcaoPrincipal(Xn)/(funcaoPrincipal(pontoA) - funcaoPrincipal(Xn))) * (Xn - pontoA));
        delta = fabs(Xn - XnMaisUm);  //Define o delta como |Xn - Xn+1|

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, funcaoPrincipal(Xn), XnMaisUm, delta);
        printf("\n----------------------------------------------------------------------");

        Xn = XnMaisUm;           //Xn passa a ser Xn+1 anterior
        L++;                     //Incrementa +1

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, delta);
    system("pause");

}

void metodoDoPontoFixo(double pontoDoInterv, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    int L = 0;                   //Conta interacoes

    delta = epsilon;        //Define delta igual o epsilon para entrar no loop
    Xn = pontoDoInterv;     //define Xn como o ponto digitado do intervalo
    messagens(10);
    messagens(11);

    //Enquanto o delta for maior ou igual a tolerancia, repete o loop
    while(delta >= epsilon){
        
        //Nao define a Xn igual XnMaisUm na primera rodada
        if(L != 0 )Xn = XnMaisUm;

        XnMaisUm = funcaoInteracao(Xn);  //Define o XnMaisUm igual ao g(Xn)
        delta = fabs(XnMaisUm - Xn);     //Define delta como |Xn - XnMaisUm|

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf |",
        L, Xn, funcaoPrincipal(Xn), XnMaisUm, delta);
        printf("\n----------------------------------------------------------------------");

        L++; //Incrementa +1 sempre que rodar o loop

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, delta);
    system("pause");

}

void metodoDeNewtonRaphson(double pontoDoInterv, double epsilon){

    double Xn;                   //Primeiro valor a ser ultilizado
    double XnMaisUm;             //Proximo valor
    double delta;                //Armazena o erro calculado |Xn - XnMaisUm|
    int L = 0;                   //Conta interacoes

    delta = epsilon;        //Define delta igual o epsilon para entrar no loop
    Xn = pontoDoInterv;     //define Xn como o ponto digitado do intervalo
    messagens(12);
    messagens(13);

    //Enquanto o delta for maior ou igual a tolerancia, repete o loop
    while(delta >= epsilon){
        
        //Nao define a Xn igual XnMaisUm na primera rodada
        if(L != 0 )Xn = XnMaisUm;

        XnMaisUm = (Xn - (funcaoPrincipal(Xn)/funcaoDerivada(Xn)));  //Define o XnMaisUm igual ao g(Xn)
        delta = fabs(XnMaisUm - Xn);                                 //Define delta como |Xn - XnMaisUm|

        printf("\n| %2d | %13.9lf | %13.9lf | %13.9lf | %13.9lf | %13.9lf |", 
        L, Xn, funcaoPrincipal(Xn), funcaoDerivada(Xn), XnMaisUm, delta);
        printf("\n--------------------------------------------------------------------------------------");

        L++; //Incrementa +1 sempre que rodar o loop

    }

    //Imprime a solucao com o erro dado por |Xn+1 - Xn|
    printf("\n\nSolucao: s = %.9lf +/- %.9lf\n", XnMaisUm, delta);
    system("pause");

}

void messagens(int resposta){

    /*"resposta" recebe o valor na chamada da funcao, e de acordo com esse valor 
    define qual o caso no switch*/
    switch (resposta){

        case 1: printf("\n\nDigite o intervalo (Ex:1 2): ");
            break;

        case 2: printf("\n\nIntervalo invalido digitado\n");
            break;
        
        case 3: printf("\n\n\t\t\t\t\t          METODO BISSECAO\n");
            break;

        case 4: printf("\n  %2s   %13s   %13s   %13s   %13s   %13s   %13s  %13s", "n", 
                "a", "b", "m", "f(a)", "f(b)", "f(m)", "|b - a|");
            printf("\n----------------------------------------------------------------------------------------------------------------------");
            break;

        case 5: printf("\n\n\t\t\tMETODO DAS CORDAS\n");
            break;

        case 6: printf("\n  %2s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "f(Xn)", "Xn+1", "|Xn+1 - Xn|");
            printf("\n----------------------------------------------------------------------");
            break;

        case 7: printf("\n\nDigite um ponto no intervalo: ");
            break;

        case 8: printf("\n\nPonto fora do intervalo digitado\n");
            break;

        case 9: printf("\n\nDigite uma tolerancia aceitavel: ");
            break;

        case 10: printf("\n\n\t\t\tMETODO DO PONTO FIXO\n");
            break;

        case 11: printf("\n  %2s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "f(Xn)", "Xn+1", "|Xn+1 - Xn|");
            printf("\n----------------------------------------------------------------------");
            break;

        case 12: printf("\n\n\t\t\t      METODO DE NEWTON RAPHSON\n");
            break;

        case 13: printf("\n  %2s   %13s   %13s   %13s   %13s   %13s  ", "n", 
                "Xn", "f(Xn)", "f'(Xn)", "Xn+1", "|Xn+1 - Xn|");
            printf("\n--------------------------------------------------------------------------------------");
            break;

        case 14: printf("\n\nErro invalido digitado\n");
            break;                     
    
        default:
            break;
    }

}