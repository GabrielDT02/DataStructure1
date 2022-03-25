/*
Gabriel Dineck Tremarin

5º Crie uma variável int x, e passe essa variável para uma função soma. Esta função soma deve receber como parâmetros os seguintes argumentos: um ponteiro para a variável X e dois números A e B. O resultado da soma deve ser atribuído à variável X. Exemplo da função: Soma(int *x, int a, int b); (1 ponto);
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void soma(int *x, int a, int b){
    *x = a+b;
}


int main(){
   
    int X;
    soma(&X,6,10);
    printf("6 + 10 = %d\n", X);

    return 0;
}