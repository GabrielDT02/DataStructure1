/*
Gabriel Dineck Tremarin

6º Crie um vetor com memória alocada de forma dinâmica utilizando a função malloc; (1 ponto);
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //vetor dinamicamente alocado
    float *ponteiro = malloc(15*sizeof(float));
    for(int i = 0; i < 15; i++){
        ponteiro[i] = i;
        printf("%.1f  ",ponteiro[i]);
    }
    printf("\n");
   
    return 0;
}