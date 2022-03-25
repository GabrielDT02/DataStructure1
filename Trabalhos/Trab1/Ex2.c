/*
Gabriel Dineck Tremarin

2º Crie uma função que leia o arquivo clientes.txt e exiba na tela as informações do arquivo; (2 pontos);
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void lerArquivo(char nomeArquivo[20]){

    int codigo;
    char nome[50];
    float saldo;

    FILE *arquivo; //variável do tipo FILE 
    arquivo = fopen(nomeArquivo,"r");//leitura do arquivo
    fscanf(arquivo,"Codigo:Nome:Saldo");


    while (fscanf(arquivo,"%d:%[^:]:%f \n", &codigo, nome, &saldo)==3){
        printf("Código: %d\n",codigo);
        printf("Nome: %s\n",nome);
        printf("Saldo: %f\n\n",saldo);
        
     
    }
   
    fclose(arquivo);

}



int main(){
    
    lerArquivo("pessoas.txt");   
    return 0;
}