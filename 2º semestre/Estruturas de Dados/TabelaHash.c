#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definicoes:

#define SIZE 11

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct {
    Elemento *tab[SIZE];
} TabelaHash;

// funcoes:

int calculaHash(int valor){
    return valor % SIZE;
}

void inicializaTabelaHash(TabelaHash *th) {
    for(int i = 0; i < SIZE; i++){
        th->tab[i] = NULL;
    }
}

void insereTabelaHash(TabelaHash *th, int valor) {
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = NULL;
    int posicao = calculaHash(valor);

    if(th->tab[posicao] == NULL){ // posicao ainda vazia
        th->tab[posicao] = novo;
    }
    else { // ja ha elementos vinculados a posicao
        Elemento *aux = th->tab[posicao];
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo; // insere ao final
    }
}

void busca(TabelaHash *th, int chave){
    int posicao = calculaHash(chave);
    if(th->tab[posicao] == NULL){
        printf("\nChave de busca %d nao encontrada", chave); // nenhum elemento vinculado a posicao
    }
    else {
        Elemento *aux;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo){
            if(chave == aux->valor){
                printf("\nChave de busca %d encontrada", chave);
                return;
            }
        } 
        printf("\nChave de busca %d nao encontrada", chave);  // percorreu todos os vinculados a posicao e nao encontrou      
    }    
}

void removeElemento(TabelaHash *th, int chave){
    int posicao = calculaHash(chave);
    if(th->tab[posicao] == NULL){
        printf("\nChave de busca %d nao encontrada", chave);
    }
    else {
        Elemento *aux, *anterior;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo){
            if (aux->valor == chave){
                if (aux == th->tab[posicao]) { //verifica se é o primeiro
                    th->tab[posicao] = th->tab[posicao]->proximo; //atualiza vetor com o novo primeiro
                } 
                else {
                    anterior->proximo = aux->proximo; //anterior aponta para o proximo de aux;
                }
                free(aux); //apaga o aux
                return;
            }
            anterior = aux; //controla o anterior
        }
        printf("\nChave de busca %d nao encontrada", chave); // percorreu todos os vinculados a posicao e nao encontrou 
    }   
}

void printa(TabelaHash *th){
    for(int i = 0; i < SIZE; i++){
        if (th->tab[i] == NULL){  // posicao vazia, nenhum elemento vinculado
            printf("\nposicao [%d]: []", i);    
        }
        else {
            printf("\nposicao [%d]: ", i);
            Elemento *aux;
            for (aux = th->tab[i]; aux != NULL; aux = aux->proximo){ // ha elementos; percorre exibindo todos
                printf("%d ", aux->valor); 
            }                                    
        }
    }
}

int main(){
    TabelaHash th;
    inicializaTabelaHash(&th);
    printf("\n\nTabela vazia: \n");
    printa(&th);

    insereTabelaHash(&th, 7);
    insereTabelaHash(&th, 17);
    insereTabelaHash(&th, 36);
    insereTabelaHash(&th, 100);
    insereTabelaHash(&th, 106);
    insereTabelaHash(&th, 205);
    printf("\n\nTabela apos insercoes: \n");
    printa(&th);
    
    printf("\n\nBuscando elementos: \n");
    busca(&th, 14);
    busca(&th, 205);

    removeElemento(&th, 205);
    removeElemento(&th, 7);
    removeElemento(&th, 106);
    printf("\n\nTabela apos remocoes: \n");
    printa(&th);

    return 0;
}