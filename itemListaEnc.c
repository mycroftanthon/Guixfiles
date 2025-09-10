#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemListaEnc.h"

struct item {
    int chave;
    int codigo;
    char nome[50];
    char plataforma[50];
    int ano;
    char estado[12];
};

struct celula {
    Item item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista * criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista)); //aloca memória de forma dinâmica
    lst->primeira = NULL;
    return lst;
}


void imprimeLista(Lista *lst){
//void imprimeLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {

    Celula *aux;
    // vai em célula por célula até chegar na última com NULL;
    for(aux = lst->primeira; aux!= NULL; aux=aux->prox)
        {
            printf("\nChave: %d\n", aux->item.chave);
            printf("\nCódigo de identificação: %d\n", aux->item.codigo);
            printf("\nNome do jogo: %s\n", aux->item.nome);
            printf("\nNome da plataforma: %s\n", aux->item.plataforma);
            printf("\nAno de lançamento: %d\n", aux->item.ano);
            printf("\nEstado do jogo: %s\n", aux->item.estado);


    }

}
/*void imprimeLista(Lista *lst) {
    Celula *aux;
    //Avança de célula em célula até chegar na última que aponta para NULL
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("\nChave: %d\n", aux->item.chave);
        //Demais campos
    }
}*/

//retorna a celula do item com a chave procurada ou NULL se não encontrou
Celula * buscaPorChave(Lista *lst, int chave) { //usar essa função para implementar e ver se o jogo já existe ou não
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}
Celula *buscaPorCodigo(Lista *lst, int codigo){
  Celula *aux = lst->primeira;
  while(aux != NULL && aux->item.codigo != codigo){
    aux = aux->prox;
  }
  return aux;
}
//retorna 1 se a lista está vazia ou 0 se não está
int verificaListaVazia(Lista *lst) {
    return lst->primeira == NULL;
}
// itens a serem adicionados char nome[50]; char plataforma[50]; int ano;char estado[12];

//void insereInicioLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {

//void insereInicioLista(Lista *lst, int chave, int codigo,char nome[50]) {
void insereInicioLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {
    //Cria novo item que vai ser guardado na lista


    Celula *jogoExistente = buscaPorCodigo(lst, codigo); //verifica se o jogo já foi inserido

    if(jogoExistente != NULL){
      printf("Erro, jogo esta na lista! ");
      return;
    }


    Item novo;
    novo.chave = chave;
    novo.codigo = codigo;
    strcpy(novo.nome, nome);
    strcpy(novo.plataforma , plataforma);
    novo.ano = ano;
    strcpy(novo.estado, estado);
    //Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;



    //Inserção no início: a próxima célula é aquela que era a primeira
    nova->prox = lst->primeira;
    //A primeira agora a é a nova célula
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave, int codigo, char nome[], char plataforma[], int ano, char estado[]) {
    //Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    novo.codigo = codigo; //codigo vai ser guardado na lista

    strcpy(novo.nome, nome);
    strcpy(novo.plataforma, plataforma);
    novo.ano = ano;
    strcpy(novo.estado, estado);
    //Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inserção no fim
    nova->prox = NULL; //a nova célula vai ser a última
    if (verificaListaVazia(lst))
    {
        //se a lista está vazia, quem vai apontar para a nova é a primeira
        lst->primeira = nova;
    }
    else
    {
        //se não está vazia, quem vai apontar para a nova é a que era última
        Celula *ultima;
        ultima = lst->primeira;
        while (ultima ->prox != NULL) //localiza a última célula
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //após a última célula, insere a nova
    }
}

//Insere a nova chave após a célula que contém a chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x);
    if (aux != NULL) {
        //Cria novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //Cria nova célula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inserção no meio
        nova->prox = aux->prox; //nova célula aponta para o endereço apontado pela anterior
        aux->prox = nova; //célula anterior passa a apontar para a nova célula
    }
    else
    {
        printf("\nO item informado não existe. \n");
    }
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //Libera uma célula por vez
    }
    free(lst); //Libera a lista
}

void apagarJogo(Lista *lst, int codigo){
    Celula *aux = lst->primeira;
    Celula *anterior;

    if(verificaListaVazia(lst)){
        printf("lista vazia, nada a retornar\n");
        return;
    }

    while(aux != NULL && aux->item.codigo != codigo){
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        printf("Jogo nao encontrado.\n");
        return;
    }
    if(aux == lst->primeira){ //remove do começo
        lst->primeira = aux->prox;
    }else{
        anterior->prox = aux->prox;

    }
    free(aux);



}
void removeItem(Lista *lst, int codigo) {
    Celula *aux = lst->primeira;
    Celula *anterior;
    while (aux != NULL && aux->item.chave != codigo)
    {
        anterior = aux; //guarda quem é a célula anterior
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("\nItem nao encontrado.\n");
        return;
    }
    if (aux == lst->primeira) //remove do início
    {
        lst->primeira = aux->prox;
    }
    else //remove do meio ou do fim
    {
        anterior->prox = aux->prox;
    }
    free(aux);
}

Lista* copiaConjunto(Lista *lst_comeco)
{
    Lista *lst_chegada = criaListaVazia();

    Celula *aux = lst_chegada->primeira;

    while(aux != NULL){
        if(strcmp(aux->item.estado, "Finalizado") == 0){
            insereFimLista(lst_chegada,
                aux->item.chave,
                aux->item.codigo,
                aux->item.nome,
                aux->item.plataforma,
                aux->item.ano,
                aux->item.estado);
            }
            aux = aux->prox;

        }

        return lst_chegada;

    }




