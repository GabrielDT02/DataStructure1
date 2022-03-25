//Gabriel Dineck Tremarin

#include<stdio.h>
#include<string.h>

struct pessoa{
    int codigo;
    char nome[50];
    float saldo;
};


void funcao(int * codigo, char nome[50], float * saldo){

    *codigo = 215;
    strcpy(nome,"Gabriel Dineck Tremarin");
    *saldo = -999.99;
}



int main(){

    struct pessoa p;
    funcao(&p.codigo, p.nome, &p.saldo);
    

    printf("Código: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Saldo: %.2f\n", p.saldo);
 
   
    return 0;
}