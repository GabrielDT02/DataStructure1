//Gabriel Dineck Tremarin
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//DECLARANDO O STRUCT
struct pessoa{
    char nome[40];
    int codigo;
    float saldo;
    struct pessoa *prox;
};


//INICIANDO A LISTA ENCADEADA
struct pessoa *iniciarLista(){
    return NULL;
}

//INSERINDO ELEMENTO NO ÍNICIO DA LISTA
struct pessoa *inserirInicio(struct pessoa *lista, char nome[40], int codigo, float saldo){
    struct pessoa *novo = malloc(sizeof(struct pessoa));
    strcpy(novo->nome,nome);
    novo->codigo = codigo;
    novo->saldo = saldo;
   
    if (lista == NULL){
        novo->prox = NULL;
        return novo;
    }else{
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}


//IMPRIMINDO A LISTA
void imprimirLista(struct pessoa *lista){
    struct pessoa *aux = lista;
    if (lista == NULL){
        printf("A lista esta vazia \n");
    }else{
        while (aux != NULL){
            printf("Nome: %s \n", aux->nome);
            printf("Código: %d \n", aux->codigo);
            printf("Saldo: R$ %.2lf \n\n", aux->saldo);
            aux = aux->prox;
            }
    }
}

// BUSCANDO ELEMENTO SEU PELO CÓDIGO
void buscarElemento(struct pessoa *lista, int codigo){
    struct pessoa *aux = lista;
    while (aux != NULL && aux->codigo != codigo){
        aux = aux->prox;
    }
    if(aux != NULL){
        printf("Código: %d\n",aux->codigo);
        printf("Nome: %s\n",aux->nome);
        printf("Saldo: R$ %.0lf\n\n", aux->saldo);
    }else{
        printf("Não tem ninguém com esse código!\n");
    }
}


//FUNÇÃO PARA REMOVER UM ELEMENTO DA LISTA
struct pessoa *removerElemento(struct pessoa *lista, int codigo){
    struct pessoa *aux = lista;
    struct pessoa *ant = NULL;

    while (aux != NULL && codigo != aux->codigo){
        ant = aux;
        aux = aux->prox;
    }
    
    if (aux == NULL){
        printf("Não tem ninguém com esse código!\n");
        return lista;
    }

    else if (aux != NULL){
        if(ant == NULL){
            lista = aux->prox;
        }else{
            ant->prox = aux->prox;
        }
        free(aux);
    }


return lista;

    
}

//FUNÇÃO PARA INSERIR FUNÇÃO NO FINAL DA LISTA
struct pessoa *inserirFinal(struct pessoa *lista, char nome[40], int codigo, float saldo){
	struct pessoa *novo = malloc(sizeof(struct pessoa));
    struct pessoa *aux = lista;

	novo->codigo = codigo;
	strcpy(novo->nome, nome);
	novo->saldo = saldo;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
	novo->prox = NULL;
	aux->prox = novo;

    return lista;
}



int main(){

  struct pessoa *lista;

  //INICIANDO A LISTA
  lista = iniciarLista();

  //INSERINDO ALGUMAS PESSOAS
  lista = inserirInicio(lista, "Daniela Mercury", 1, 34540);
  lista = inserirInicio(lista, "Gilberto Gil", 2, 6540);
  lista = inserirInicio(lista, "Ney Matogrosso", 3, 75430);
  lista = inserirInicio(lista, "Sidney Magal", 4, 98760);
  lista = inserirInicio(lista, "Elis Regina", 5, 78920);
  lista = inserirInicio(lista, "Maria Bethania", 6, 979923);
  lista = inserirInicio(lista, "Caetano Veloso", 7, 890234);
  lista = inserirInicio(lista, "Roberto Carlos", 8, 50543);
  lista = inserirInicio(lista, "Chico Buarque", 9, 8765430);
  lista = inserirInicio(lista, "Rita Lee", 10, 345678);
  
  //IMPRIMINDO A LISTA
  printf("\n\n==================================================\n");
  imprimirLista(lista);
  printf("==================================================\n");
  
  //PESQUISANDO POR ALGUÉM PELO CÓDIGO
  buscarElemento(lista, 8);

 //REMOVENDO O CAETANO VELOSO DA LISTA
  lista = removerElemento(lista,7);
  buscarElemento(lista, 7);

 //INSERINDO ELEMENTOS NO FINAL DA LISTA
 lista = inserirFinal(lista, "Gal Costa", 11, 345430);
 lista = inserirFinal(lista, "Sergio Reis", 12, 129580);

 //IMPRIMINDO A LISTA NOVAMENTE
 printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
 imprimirLista(lista);
 printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    return 0;
}