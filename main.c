#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemListaEnc.h"

// Funcao auxiliar para limpar o buffer do teclado
void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    Lista *lst;
    int vazia, chave, codigo, ano, opcao;
    char plataforma[50], estado[12], nome[50];

    printf("Criado lista vazia.\n");
    lst = criaListaVazia();

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d\n", vazia);

    do{



    //void lerDados(int *chave, int *codigo, char nome[], char plataforma[], int *ano, char estado[]){
    printf("\n--- MENU DE OPCOES ---\n");
    printf("1. Inserir novo elemento\n");
    printf("2. Excluir elemento\n");
    printf("3. Buscar elemento\n");
    printf("4. Imprimir todos os elementos\n");
    printf("5. Copiar conjunto e imprimir\n");
    printf("6. Sair (destruindo a estrutura)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    //limpa_buffer();



    limpa_buffer(); // Limpa o buffer depois de ler o numero
    switch(opcao){
        case 1:
        {
            printf("Digite a chave: ");
            scanf(" %d ", &chave);
            limpa_buffer();

            printf("Digite o codigo:\n ");
            scanf("%d", &codigo);
            //limpa_buffer();

            printf("Digite o nome do jogo: \n   ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0; // Tira o '\n'

            printf("Digite a plataforma (PC, PS5, Xbox, Switch, Mobile): ");
            fgets(plataforma, sizeof(plataforma), stdin);
            plataforma[strcspn(plataforma, "\n")] = 0;
            limpa_buffer();
            do{
                printf("Digite o ano de lancamento: ");
                scanf("%d", &ano);
                if(ano <1990 || ano > 2025){
                printf("O ano deve ser entre 1990 e 2025\n");
                limpa_buffer();
                int plataformaValida = 0;
                if (strcmp(plataforma, "PC") == 0 ||
            strcmp(plataforma, "PS5") == 0 ||
            strcmp(plataforma, "Xbox") == 0 ||
            strcmp(plataforma, "Switch") == 0 ||
            }
            strcmp(plataforma, "Mobile") == 0) {
            plataformaValida = 1;
        } else {
            printf("Plataforma invalida. Tente novamente.\n");
        }
    } while (!plataformaValida);
        limpa_buffer();
        while(ano <1990 || ano > 2025);
            limpa_buffer();
            int estadoValida = 0;
    do{
        printf("Digite o estado: ");
        fgets(estado, sizeof(estado), stdin);
        estado[strcspn(estado, "\n")] = 0;

    if(strcmp(estado, "Finalizado") == 0 ||
       strcmp(estado, "Jogando") == 0    ||
       strcmp(estado, "Por jogar") == 0) {
       estadoValida = 1;

      }else{
	 printf("Estado invalido. ");
      }
    } while(!estadoValida);


       }
    }





                }
    }




