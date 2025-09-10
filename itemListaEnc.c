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
    Lista *lst = malloc(sizeof(Lista)); //aloca mem�ria de forma din�mica
    lst->primeira = NULL;
    return lst;
}


void imprimeLista(Lista *lst){
//void imprimeLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {

    Celula *aux;
    // vai em c�lula por c�lula at� chegar na �ltima com NULL;
    for(aux = lst->primeira; aux!= NULL; aux=aux->prox)
        {
            printf("\nChave: %d\n", aux->item.chave);
            printf("\nC�digo de identifica��o: %d\n", aux->item.codigo);
            printf("\nNome do jogo: %s\n", aux->item.nome);
            printf("\nNome da plataforma: %s\n", aux->item.plataforma);
            printf("\nAno de lan�amento: %d\n", aux->item.ano);
            printf("\nEstado do jogo: %s\n", aux->item.estado);


    }

}
/*void imprimeLista(Lista *lst) {
    Celula *aux;
    //Avan�a de c�lula em c�lula at� chegar na �ltima que aponta para NULL
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("\nChave: %d\n", aux->item.chave);
        //Demais campos
    }
}*/

//retorna a celula do item com a chave procurada ou NULL se n�o encontrou
Celula * buscaPorChave(Lista *lst, int chave) { //usar essa fun��o para implementar e ver se o jogo j� existe ou n�o
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
//retorna 1 se a lista est� vazia ou 0 se n�o est�
int verificaListaVazia(Lista *lst) {
    return lst->primeira == NULL;
}
// itens a serem adicionados char nome[50]; char plataforma[50]; int ano;char estado[12];

//void insereInicioLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {

//void insereInicioLista(Lista *lst, int chave, int codigo,char nome[50]) {
void insereInicioLista(Lista *lst, int chave, int codigo, char nome[50], char plataforma[50], int ano, char estado[12]) {
    //Cria novo item que vai ser guardado na lista


    Celula *jogoExistente = buscaPorCodigo(lst, codigo); //verifica se o jogo j� foi inserido

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
    //Cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;



    //Inser��o no in�cio: a pr�xima c�lula � aquela que era a primeira
    nova->prox = lst->primeira;
    //A primeira agora a � a nova c�lula
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
    //Cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inser��o no fim
    nova->prox = NULL; //a nova c�lula vai ser a �ltima
    if (verificaListaVazia(lst))
    {
        //se a lista est� vazia, quem vai apontar para a nova � a primeira
        lst->primeira = nova;
    }
    else
    {
        //se n�o est� vazia, quem vai apontar para a nova � a que era �ltima
        Celula *ultima;
        ultima = lst->primeira;
        while (ultima ->prox != NULL) //localiza a �ltima c�lula
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //ap�s a �ltima c�lula, insere a nova
    }
}

//Insere a nova chave ap�s a c�lula que cont�m a chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x);
    if (aux != NULL) {
        //Cria novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //Cria nova c�lula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inser��o no meio
        nova->prox = aux->prox; //nova c�lula aponta para o endere�o apontado pela anterior
        aux->prox = nova; //c�lula anterior passa a apontar para a nova c�lula
    }
    else
    {
        printf("\nO item informado n�o existe. \n");
    }
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //Libera uma c�lula por vez
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
    if(aux == lst->primeira){ //remove do come�o
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
        anterior = aux; //guarda quem � a c�lula anterior
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("\nItem nao encontrado.\n");
        return;
    }
    if (aux == lst->primeira) //remove do in�cio
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




