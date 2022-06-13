#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    double funcaoGdeX;
    double x = 0;

    funcaoGdeX = tan((1/(exp(x))));
    printf("%lf", funcaoGdeX);

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