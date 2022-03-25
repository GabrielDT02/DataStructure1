/*
Gabriel Dineck Tremarin

7º Crie uma matriz com memória alocada de forma dinâmica utilizando a função malloc; (2 pontos); ESSE EXERCÍCIO REQUER UMA PESQUISA, OU AINDA UMA LIDA NO MATERIAL QUE FOI PASSADO.   
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
     int linhas = 5, colunas = 4;

    int **matriz;
    matriz = malloc(colunas*sizeof(int));

    for(int i = 0; i < colunas; i++){
       matriz[i] =  malloc(linhas*sizeof(int));
    }

    for(int i = 0; i < colunas; i++){
        
        for(int j = 0; j < linhas; j++){

            if(j%2 == 0){
                matriz[i][j] = 1;
            }
            else{
                matriz[i][j] = 2;
            }
            printf("%d  ",matriz[i][j]);   
        }
        printf("\n");
    }
}