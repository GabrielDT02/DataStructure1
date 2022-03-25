//Gabriel Dineck Tremarin

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM_PESSOAS 10


struct pessoa{
    int codigo;
    char nome[50];
    float saldo;
};


void funcao(struct pessoa p[NUM_PESSOAS]){
        int codigo;
        char nome[50];
        float saldo;

    for(int i = 0; i < NUM_PESSOAS; i++){


        printf("\n********************** Pessoa %d **********************\n", i+1);
        printf("Código: ");
        scanf("%d", &codigo);


        printf("Nome: ");
        scanf(" %[^\n]", nome);

        printf("Saldo: ");
        scanf("%f", &saldo);

        p[i].codigo = codigo;
        strcpy(p[i].nome,nome);
        p[i].saldo = saldo;
        system("clear");
        
    }

    for(int i = 0; i < NUM_PESSOAS; i++){
        printf("\n********************** Dados da pessoa %d **********************\n", i+1);
        printf("Código: %d\nNome: %s\nSaldo: %.2f\n", p[i].codigo, p[i].nome, p[i].saldo);

    }
    

}//Fim da funcao

int main(){

    struct pessoa p[NUM_PESSOAS];
    funcao(p);

    return 0;

}