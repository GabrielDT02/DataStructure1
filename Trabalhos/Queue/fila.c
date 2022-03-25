#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARAR O STRUCT
typedef struct Cliente
{
    char codigo[5];
    char nome[40];
    struct Cliente *prox;
} cliente;

//INICIAR A FILA
cliente *iniciarFila(cliente *fila)
{
    return NULL;
}

//FUNÇÃO PARA ENFILEIRAR NOVOS CLIENTES
cliente *enfileirar(cliente *fila, char codigo[5], char nome[40])
{
    cliente *novo = malloc(sizeof(cliente));
    cliente *aux = fila;
    novo->prox = NULL;

    strcpy(novo->codigo, codigo);
    strcpy(novo->nome, nome);

    if (fila == NULL)
    {
        return novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
        return fila;
    }
}

//FUNÇÃO PARA ENTRAR, CADASTRAR, O CLIENTE NA FILA;
cliente *entrarParaFila(cliente *fila, cliente *fila2)
{
    cliente *aux = fila;
    cliente *aux2 = fila2;
    int aux_strcmp = 999;
    int aux2_strcmp = 999;
    /*aux_strcmp e aux2_strcmp são variaveis usadas para comparar o novo código com os códigos já existentes,
    ou seja, impedir que tenham duas pessoas com o mesmo código. */

    char codigo[5], nome[40];
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    printf("Código: ");
    scanf("%s", codigo);



    /*Eu criei dois laços com o while onde eu vou comparar o código de entrada
     com os códigos já existentes nas duas filas (preferencial e normal)*/
    while (aux != NULL)
    {
        aux_strcmp = strcmp(codigo, aux->codigo);


        if (aux_strcmp == 0)
        {
            printf("Esse código já está cadastrado, tente novamente\n");
            break;
        }
        aux = aux->prox;
        
    }

    while (aux2 != NULL)
    {
        aux2_strcmp = strcmp(codigo, aux2->codigo);
        if (aux2_strcmp == 0)
        {
            printf("Esse código já está cadastrado, tente novamente\n");
            break;
        }
        aux2 = aux2->prox;   
    }

    /* se não houver nenhum código igual nas filas, 
    a pessoa vai entrar para a fila*/
   if (aux_strcmp != 0 && aux2_strcmp != 0)
    {
        fila = enfileirar(fila, codigo, nome);
        
    }

     return fila;           
    
}

//FUNÇÃO PARA DESENFILEIRAR CLIENTES, COMEÇANDO PELA FILA PREFERENCIAL
cliente *desenfileirar(cliente *fila)
{
    cliente *aux = fila;
    cliente *prox = NULL;
    prox = aux->prox;
    fila = prox;
    free(aux);
    return fila;
}

//FUNÇÃO PARA LER OS ARQUIVOS
cliente *lerArquivo(cliente *fila, char nomeArquivo[30])
{
    char codigo[5];
    char nome[40];

    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    fscanf(arquivo, "Codigo,Nome Completo");

    //esse loop vai passar a lista do arquivo para a fila
    while (fscanf(arquivo, " %[^,],%[^\n] \n", codigo, nome) == 2)
    {
        fila = enfileirar(fila, codigo, nome);
    }

    fclose(arquivo);
    return fila;
}

//IMPRIMIR A FILA
void exibir(cliente *fila)
{
    cliente *aux;

    if (fila == NULL)
    {
        printf("Não tem ninguém na fila \n");
    }
    else
    {

        aux = fila;
        while (aux != NULL)
        {
            printf("Código: %s\n", aux->codigo);
            printf("Nome: %s\n\n", aux->nome);

            aux = aux->prox;
        }
    }
}

//PROCURAR CLIENTES
void buscar(cliente *fila, cliente *fila2)
{
    cliente *aux = fila;
    cliente *aux2 = fila2;
    int aux_strcmp = 999;
    int aux2_strcmp = 999;
    char codigo[5];
    printf("Código: ");
    scanf("%s", codigo);

    while (aux != NULL)
    {
        aux_strcmp = strcmp(codigo, aux->codigo);
        if (aux_strcmp == 0)
        {
            break;
        } 
        aux = aux->prox;
    }

    while (aux2 != NULL)
    {
        aux2_strcmp = strcmp(codigo, aux2->codigo);
        if (aux2_strcmp == 0)
            break;
        aux2 = aux2->prox;
    }

    if (aux_strcmp == 0)
        printf("%s está na fila normal!\n", aux->nome);

    if (aux2_strcmp == 0)
        printf("%s está na fila preferêncial!\n", aux2->nome);

    if (aux2_strcmp != 0 && aux_strcmp != 0)
        printf("Tente novamente\n");
}

//FUNÇÃO PARA GRAVAR OS ARQUIVOS
void gravarArquivo(cliente *fila, char nomeArquivo[30])
{
    cliente *aux = fila;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
    fprintf(arquivo, "Codigo,Nome Completo");
    while (aux != NULL)
    {
        fprintf(arquivo, "\n%s,%s", aux->codigo, aux->nome);
        aux = aux->prox;
    }
    fclose(arquivo);
}

int main()
{

    cliente *normal = iniciarFila(normal);//FILA DE ATENDIMENTO NORMAL
    cliente *preferencial = iniciarFila(preferencial); //FILA DE ATENDIMENTO PREFERENCIAL

    normal = lerArquivo(normal, "normal.txt");
    preferencial = lerArquivo(preferencial, "preferencial.txt");

    int x;
    char y = 's';
    while (y == 's')
    {
        printf("=====================================\n");
        printf("==  TRABALHO DE ESTRUTRA DE DADOS  ==\n");
        printf("=====================================\n\n");

        printf("Selecione uma opção para continuar:\n");
        printf("1 - Enfileirar (fila normal)\n");
        printf("2 - Enfileirar (fila preferencial)\n");
        printf("3 - Desenfileirar\n");
        printf("4 - Buscar\n");
        printf("5 - Exibir\n");
        printf("6 - Fechar programa\n");
        printf("-- ");
        scanf("%d", &x);

        while (x < 1 || x > 6)
        {
            printf("-- ");
            scanf("%d", &x);
        }
        printf("\n");
        if (x == 1)
        {
            normal = entrarParaFila(normal, preferencial);
            gravarArquivo(normal, "normal.txt");
        }
        else if (x == 2)
        {
            preferencial = entrarParaFila(preferencial, normal);
            gravarArquivo(preferencial, "preferencial.txt");
        }
        else if (x == 3)
        {
            if (preferencial != NULL)
            {
                preferencial = desenfileirar(preferencial);
                gravarArquivo(preferencial, "preferencial.txt");
            }
            else if (normal != NULL)
            {
                normal = desenfileirar(normal);
                gravarArquivo(normal, "normal.txt");
            }
            else
            {
                printf("Não tem ninguém nas duas filas.\n");
            }
        }
        else if (x == 4)
        {
            buscar(normal, preferencial);
        }

        else if (x == 5)
        {
            printf("-----------FILA NORMAL-----------\n");
            exibir(normal);
            printf("\n\n\n");
            printf("-----------FILA PREFERECIAL-----------\n");
            exibir(preferencial);
        }

        else if (x == 6)
            break;

        printf("Deseja continuar? [s/n] ");
        scanf(" %c", &y);
        while (y != 's' && y != 'n')
        {
            printf("Deseja continuar? [s/n] ");
            scanf(" %c", &y);
        }
        system("clear");
    }

    return 0;
}