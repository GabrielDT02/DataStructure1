/*
Gabriel Dineck Tremarin

4º Crie uma função que leia os dados de um arquivo e armazene as informações em uma variável do tipo estrutura Pessoa definida anteriormente; (2 pontos);
*/


#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct Pessoa
{
    int codigo;
    char nome[50];
    float saldo;
};


void lerArquivo(char nomeArquivo[20]){

    struct Pessoa p[5]; //5 é o numero de pessoas no arquivo pessoas.txt
    int i = 0;


    FILE *arquivo; //variável do tipo FILE 
    arquivo = fopen(nomeArquivo,"r");//leitura do arquivo
    fscanf(arquivo,"Codigo:Nome:Saldo");


    while (fscanf(arquivo,"%d:%[^:]:%f \n", &p[i].codigo, p[i].nome, &p[i].saldo)==3){
      
        /*
        printf("Código: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
        printf("Saldo: %f\n\n", p[i].saldo);
        */
        i++;
    }
    
    fclose(arquivo);

}



int main(){
    
    lerArquivo("pessoas.txt");

    return 0;
}