/*
Gabriel Dineck Tremarin

3º Utilizando a função de ler o arquivo implementada anteriormente, modifique-a para que agora ao invés os dados apenas serem exibidos na tela, os repasse para a estrutura criada no primeiro exercício. Após isso, imprima os valores armazenados na estrutura; (2 pontos)
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
        printf("Código: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
        printf("Saldo: %f\n\n", p[i].saldo);
        i++;
    }

    fclose(arquivo);

}



int main(){
    
    lerArquivo("pessoas.txt");

    return 0;
}