/*
Nome: Gabriel Dineck Tremarin
Matrícula: 2110102351

Esse programa tem o objetivo de empilhar absolutamente qualquer coisa.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha
{
    char elemento[40];
    char id[10];
    struct pilha *prox;
} Pilha;

//INICIANDO A PILHA
Pilha *iniciarPilha(Pilha *pilha)
{
    return NULL;
}

//RETORNAR O TOPO
Pilha *retornarTopo(Pilha *pilha)
{
    Pilha *topo = pilha;
    return topo;
}

//EMPILHANDO
Pilha *push(char elemento[40], char id[10], Pilha *pilha)
{

    Pilha *aux = pilha;

    /*A variavel str_cmp serve para verificar se ja existe um ID igual na pilha */
    int str_cmp = 123;
    while (aux != NULL)
    {
        str_cmp = strcmp(aux->id, id);
        /* Se str_cmp for igual a zero então o loop vai parar porque
            foi encontrado um id igual na pilha  */
        if (str_cmp == 0)
        {
            break;
        }

        aux = aux->prox;
    }

    /* Se str_cmp != 0 então não existem outros elementos com o mesmo ID,
    já que o str_cmp só é zero quando há ID's iguais */
    if (str_cmp != 0)
    {
        Pilha *novo = malloc(sizeof(Pilha));
        strcpy(novo->elemento, elemento);
        strcpy(novo->id, id);

        if (pilha == NULL)
        {
            novo->prox = NULL;
            return novo;
        }
        else
        {
            novo->prox = pilha;
        }
    }
    else
    {
        printf("\nID já existente!\n");
        return pilha;
    }
}

//DESEMPILHANDO
Pilha *pop(Pilha *pilha)
{

    Pilha *aux = pilha;

    if (aux == NULL)
    {
        printf("\nA pilha não contém elementos!\n");
    }
    else
    {
        pilha = aux->prox;
        free(aux);
    }
    return pilha;
}

//IMPRIMIR A PILHA
void imprimirPilha(Pilha *pilha)
{
    Pilha *aux = pilha;
    if (aux == NULL)
    {
        printf("\nA pilha não contém elementos!\n");
    }
    else
    {

        while (aux != NULL)
        {
            printf("\nElemento: %s\nID: %s\n", aux->elemento, aux->id);
            aux = aux->prox;
        }
    }
}



//PROCURAR ELEMENTO
void encontrarElemento(char id[10], Pilha *pilha)
{
    Pilha *aux = pilha;
    int str_cmp = 123;
    while (aux != NULL)
    {
        str_cmp = strcmp(id, aux->id);
        //se str_cmp for igual a zero o loop vai parar
        if (str_cmp == 0)
        {
            break;
        }
        aux = aux->prox;
    }
    //Se str_cmp == 0 então foi encontrado um ID igual na pilha
    if (str_cmp == 0)
    {
        printf("\nElemento: %s\nID: %s\n", aux->elemento, aux->id);
    }
    else
    {
        printf("\nID não encontrado!\n");
    }
}



//LER O ARQUIVO
Pilha *lerArquivo(Pilha *pilha, char nomeArquivo[40])
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    fscanf(arquivo, "Elemento;ID");

    char elemento[40], id[10];
    
    while (fscanf(arquivo, " %[^;];%[^\n] \n", elemento, id) == 2)
    {
        pilha = push(elemento, id, pilha);
    }

    fclose(arquivo);
    return pilha;
}



//GRAVAR O ARQUIVO
void gravarArquivo(Pilha *pilha, char nomeArquivo[30])
{
    Pilha *aux = pilha;
    FILE *arquivo = fopen(nomeArquivo, "w");
    fprintf(arquivo, "Elemento;ID\n");

    while (aux != NULL)
    {
        fprintf(arquivo, "%s;%s\n", aux->elemento, aux->id);
        aux = aux->prox;
    }

    fclose(arquivo);
}

int main()
{

    Pilha *pilha = iniciarPilha(pilha);
    Pilha *topo = NULL;
    pilha = lerArquivo(pilha, "pilha.txt");

    char elemento[40], id[10], b = 's';
    int a = 0;
    while (b == 's')
    {

        printf("DIGITE UM DOS NÚMEROS ABAIXO PARA REALIZAR UMA FUNÇÃO\n");

        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir a pilha\n");
        printf("4 - Buscar elemento\n");
        printf("5 - Imprimir o topo\n");
        printf("6 - Fechar programa\n");
        printf("Digite aqui: ");
        scanf("%d", &a);

        if (a == 1)
        {
            printf("\nElemento: ");
            scanf(" %[^\n]", elemento);
            printf("ID: ");
            scanf(" %[^\n]", id);

            pilha = push(elemento, id, pilha);
            gravarArquivo(pilha, "pilha.txt");
        }

        else if (a == 2)
        {
            pilha = pop(pilha);
            gravarArquivo(pilha, "pilha.txt");
        }

        else if (a == 3)
        {
            imprimirPilha(pilha);
        }

        else if (a == 4)
        {
            printf("\nID: ");
            scanf(" %[^\n]", id);
            encontrarElemento(id, pilha);
        }

        else if (a == 5)
        {
            /*Essa condicional está aqui porque quando a pilha estava vazia
              e eu chamava a função retornarTopo(), o programa dava erro*/
            if (pilha != NULL)
            {
                topo = retornarTopo(pilha);
                printf("\nTopo da pilha:\n%s - %s \n", topo->elemento, topo->id);
            }
            else
            {
                printf("\nA pilha não contém elementos!\n");
            }
        }

        else if (a == 6)
        {
            return 0;
        }

        printf("\nDeseja continuar? [s/n] ");
        scanf(" %c", &b);
        while (b != 'n' && b != 's')
        {
            printf("\nDeseja continuar? [s/n] ");
            scanf(" %c", &b);
        }

        system("clear");
    }

    return 0;
}