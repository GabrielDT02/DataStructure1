//GABRIEL DINECK TREMARIN

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DEFININDO O STRUCT
typedef struct fila {
    char codigo[5];
    char nome[40];
    struct fila *prox;
}Fila;

//INICIANDO A FILA
Fila *iniciarFila(){
    return NULL;
}

//INSERINDO ELEMENTO NO FINAL, ENFILEIRANDO
Fila *insereFim(Fila*filaa, char codigo[5], char nome[40]) {
    Fila *novo = malloc(sizeof(Fila));
    Fila *aux = filaa;
    novo->prox = NULL;
    strcpy(novo->codigo,codigo);
    strcpy(novo->nome,nome);
    
    if(filaa == NULL){
        return novo;
    } else {
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        return filaa;
    }
    
}

//REMOVENDO O PRIMEIRO ELEMENTO DA FILA, ENFILEIRANDO
Fila *removeElemento(Fila *filaa) {
    Fila *aux = filaa;
    Fila *prox = NULL;
    prox = aux->prox;
    filaa = prox;
    free(aux);
    return filaa;  
}


//IMPRIMINDO A FILA
void imprimeFila(Fila *filaa) {
    Fila*aux = filaa;
    while(aux!=NULL) {
        printf("Nome: %s\nCódigo: %s\n\n",aux->nome,aux->codigo);
        aux = aux->prox;
    }
}
int main(){

    //INICIANDO A FILA
    Fila *filaa = iniciarFila();

    //ADICIONANDO ELEMENTOS
    filaa = insereFim(filaa,"1","Gabriel Dineck Tremarin");
    filaa = insereFim(filaa,"2","João Silva");
    filaa = insereFim(filaa,"3","Maria Ribeiro");
    filaa = insereFim(filaa,"4","José Guimarẽs");
    filaa = insereFim(filaa,"5","Pedro Matos");
    filaa = insereFim(filaa,"6","Renata Castro");
    filaa = insereFim(filaa,"7","Marcos Silveira");

    //IMPRIMINDO TODOS OS ELEMENTOS DA FILA
    imprimeFila(filaa);


    //REMOVENDO OS 2 PRIMEIROS ELEMENTOS DA FILA
    printf("\n\n\nRemovendo os 2 primeiros elementos da lista......\n\n");
    filaa = removeElemento(filaa);
    filaa = removeElemento(filaa);

    //IMPRIMINDO A FILA DNV SEM OS 2 ELEMENTOS QUE FORAM REMOVIDOS
    imprimeFila(filaa);
   
    return 0;
}