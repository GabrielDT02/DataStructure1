
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//CRIANDO A ESTRUTURA
struct pessoa{
    int codigo;
    char nome[40];
    float saldo;
    struct pessoa *prox;
};



//INICIANDO A LISTA
struct pessoa *iniciarLista(){
    return NULL;
}



//VERIFICAR SE A LISTA ESTÁ VAZIA
void verificarLista(struct pessoa *lista){
    if (lista == NULL){
        printf("A lista está vazia \n");
    }else{
        printf("A lista não está vazia\n");
    }
  
}




//INSERINDO O INICIO DA LISTA
struct pessoa *inserirInicio(struct pessoa *lista, int codigo, char nome[40], float saldo){
    struct pessoa *novo = malloc(sizeof(struct pessoa));
    strcpy(novo->nome,nome);
    novo->codigo = codigo;
    novo->saldo = saldo;

    //se a lista estiver vazia
    if (lista == NULL){
        novo->prox = NULL;
        return novo;
    } else{
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}




//FUNÇÃO PARA LER O ARQUIVO
struct pessoa *lerArquivo(struct pessoa *lista, char nomeArquivo[30]){
    int codigo;
    char nome[40];
    float saldo;

    FILE *arquivo;  
    arquivo = fopen(nomeArquivo,"r");
    fscanf(arquivo,"Codigo,Nome Completo,Saldo");

    //esse loop vai passar a lista do arquivo para a lista encadeada
    while (fscanf(arquivo,"%d,%[^,],%f \n", &codigo, nome, &saldo)==3){
      lista = inserirInicio(lista, codigo, nome, saldo);

    }

    fclose(arquivo);
    return lista;
}



// IMPRIMINDO A LISTA
void imprimirLista(struct pessoa *lista){
    struct pessoa *aux;

    if (lista == NULL){
        printf("A lista está vazia \n");
    }else{
        
        aux = lista;
        while (aux != NULL){
            printf("Código: %d\n",aux->codigo);
            printf("Nome: %s\n",aux->nome);
            printf("Saldo: R$ %.0lf\n\n", aux->saldo);
            
            aux = aux->prox;
            

        }
    }

}



//PESQUISAR ALGUÉM DA LISTA
void buscarCliente(struct pessoa *lista){
    int codigo;
    printf("Digite o código do cliente: ");
    scanf("%d",&codigo);

    struct pessoa *aux;
    aux = lista;
    while (aux != NULL && aux->codigo != codigo){
        aux = aux->prox;

    }
    if(aux != NULL){
        printf("Código: %d\n",aux->codigo);
        printf("Nome: %s\n",aux->nome);
        printf("Saldo: R$ %.0lf\n\n", aux->saldo);
    }else{
        printf("Esse(a) cliente não está cadastrado(a)!\n");
    }

}

//GRAVANDO O ARQUIVO
void gravarArquivo(struct pessoa *lista,char nomeArquivo[30], char modo){
    struct pessoa*aux = lista;
    FILE *arquivo;

    //'w' = write
    //esse modo será usado para excluir algúem da lista
    if(modo == 'w'){
        arquivo = fopen(nomeArquivo,"w");
        fprintf(arquivo, "Codigo,Nome Completo,Saldo");
        while(aux != NULL){
            fprintf(arquivo, "\n%d,%s,%.0f", aux->codigo, aux->nome, aux->saldo);
            aux=aux->prox;
        }
    }

    //'a' para appending = adicionar, acrescentar
    //esse modo será usado para adicionar alguém na lista
    else if(modo == 'a'){
        arquivo = fopen(nomeArquivo,"a");
        fprintf(arquivo, "\n%d,%s,%.0f", aux->codigo, aux->nome, aux->saldo);
    }
    fclose(arquivo);
}



//CADASTRANDO O CLIENTE
struct pessoa *cadastrarCliente(struct pessoa *lista){
    struct pessoa*aux = lista;
    int codigo = 0;
    char nome[40];
    float saldo;

    printf("Nome: ");
    scanf(" %[^\n]",nome);
    printf("Saldo: ");
    scanf("%f",&saldo);
    printf("Código: ");
    scanf("%d",&codigo);


    //esse loop faz com que não tenham duas pessoas com o mesmo código
    while (aux != NULL){
        while(aux->codigo == codigo){
            printf("Esse código já está sendo usado, digite outro código: ");
            scanf("%d",&codigo);
        }    
    aux = aux->prox;
    }

    printf("\nCliente cadastrado com sucesso!\n");

    lista = inserirInicio(lista, codigo, nome, saldo);
    gravarArquivo(lista,"clientes.txt",'a');

    return lista;
}


//REMOVENDO ALGUÉM DA LISTA
struct pessoa *removerCliente(struct pessoa *lista)
{
    char x;
    int codigo;
    printf("Digite o código do cliente que deseja remover: ");
    scanf("%d",&codigo);

    struct pessoa *aux;
    aux = lista;
    struct pessoa *ant = NULL;
    while (aux != NULL && codigo != aux->codigo){
        ant = aux;
        aux = aux->prox;
    }
    
    //se não encontrar o código
    if (aux == NULL){
        printf("Esse(a) cliente não está cadastrado(a)!\n");
        return lista;
    }


    else if (aux != NULL){
        
        printf("Deseja remover %s da sua lista? [s/n] ",aux->nome);
        scanf(" %c",&x);
        while(x != 's' && x != 'n'){
        printf("Deseja remover %s da sua lista? [s/n] ",aux->nome);
        scanf(" %c",&x);
        }
        //se for excluir o primeiro elemento
        if(ant == NULL){
            lista = aux->prox;
        }
        //se for excluir um elemento entre o primeiro e o null
        else{
            ant->prox = aux->prox;
        }
        free(aux);
    }
        gravarArquivo(lista,"clientes.txt",'w');
        printf("Cliente removido com sucesso!\n");

return lista;

    
}

int main(){
  
  struct pessoa *lista;
  lista = iniciarLista();
  //verificarLista(lista);
  lista = lerArquivo(lista,"clientes.txt");
  int x;
  char y = 's';
    
  while(y == 's'){
    printf("=====================================\n");
    printf("==  TRABALHO DE ESTRUTRA DE DADOS  ==\n");
    printf("=====================================\n\n");

    printf("Selecione uma opção para continuar:\n"); 
    printf("1 - Cadastrar cliente\n");
    printf("2 - Remover cliente\n");
    printf("3 - Pesquisar cliente\n");
    printf("4 - Exibir todos os clientes\n");
    printf("5 - Fechar programa\n");
    printf("-- ");
    scanf("%d",&x);

    while(x < 1 || x > 5){
        printf("-- ");
        scanf("%d",&x);
    }
    printf("\n");
    if(x == 1){
        lista = cadastrarCliente(lista);
        
    }
    else if(x == 2){
     
        lista = removerCliente(lista);
    }
    else if(x == 3){
        buscarCliente(lista);
    }
    else if(x == 4){
        imprimirLista(lista);
    }
    else if(x == 5)break;

    printf("Deseja continuar? [s/n] ");
    scanf(" %c",&y);
    while(y != 's' && y != 'n'){
        printf("Deseja continuar? [s/n] ");
        scanf(" %c",&y);
    }
    system("clear");

  } 


    return 0;
}

