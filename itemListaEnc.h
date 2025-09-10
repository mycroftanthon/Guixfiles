#ifndef ITEMLISTAENC_H_INCLUDED
#define ITEMLISTAENC_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista * criaListaVazia();
void imprimeLista(Lista *lst);
Celula * buscaPorChave(Lista *lst, int chave);
Celula *buscaPorCodigo(Lista *lst, int codigo);

int verificaListaVazia(Lista *lst);
void insereInicioLista(Lista *lst, int chave, int codigo, char nome[], char plataforma[], int ano, char estado[]) ;
void insereFimLista(Lista *lst, int chave, int codigo, char nome[], char plataforma[], int ano, char estado[]);
void insereMeioLista(Lista *lst, int chave, int x);
void liberaLista(Lista *lst);
void removeItem(Lista *lst, int x);
Lista* copiaConjunto(Lista *lst_comeco);
//void (int *chave, int *codigo, char nome[], char plataforma[], int *ano, char estado[]);


#endif // ITEMLISTAENC_H_INCLUDED
