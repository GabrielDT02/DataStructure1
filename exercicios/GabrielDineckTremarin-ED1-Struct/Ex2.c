//Gabriel Dineck Tremarin

#include<stdio.h>
#include<string.h>

struct pessoa{
    int codigo;
    char nome[50];
    float saldo;
};

int main(){
    struct pessoa p;
    p.codigo = 215;
    strcpy(p.nome, "Gabriel Dineck Tremarin");
    p.saldo = -999.99;

    printf("Código: %d\nNome: %s\nSaldo: %f\n", p.codigo, p.nome, p.saldo);




    
    return 0;
}