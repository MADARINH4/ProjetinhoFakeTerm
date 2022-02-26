#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include "interface.h"

int main(void){

    char resposta = ' ';          //armazena resposta
    bool loop;                    //loop igual a true

    //enquanto loop for false
    while(!loop){

        resposta = interface();   //chama funcao interface

        switch (resposta){
            
            case 'a':

                jogo();         //chama funcao jogo
                break;

            case 'b':

                ranking();       //chama funcao raking
                break;

            case 'c':

                regras();         //chama funcao regras
                break;

            case 'd':

                return 0;

        }

    }

    return 0;

}
