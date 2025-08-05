/**
 * @file hashTabela.c
 * @author João Eduardo Pelegriin Ferrari
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma tabela hash contendo 13 posições. O índice das chaves
 *  deve ser gerado utilizando a fórmula k mod M, onde k é a chave e M a
 *  quantidade de chaves. Resolva as colisões utilizando uma Lista Encadeada.
 *  Inclua operações de inserção, remoção e busca da chave nesta tabela hash,
 *  informando se a chave foi encontrada ou não.  Atenção: os elementos da
 *  lista encadeada não precisam estar ordenados/em ordem.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 13

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct {
    Elemento *tab[SIZE];
} TabelaHash;


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

    if(th->tab[posicao] == NULL){ // POSIÇÃO VAZIA
        th->tab[posicao] = novo;
    }
    else { // POSSUI ELEMENTOS VINCULADOS
        Elemento *aux = th->tab[posicao];
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo; // INSERÇÃO NO FINAL
    }
}

void busca(TabelaHash *th, int chave){
    int posicao = calculaHash(chave);
    if(th->tab[posicao] == NULL){
        printf("\nCHAVE DE BUSCA %d NAO ENCONTRADA", chave); 
    }
    else {
        Elemento *aux;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo){
            if(chave == aux->valor){
                printf("\nCHAVE DE BUSCA %d ENCONTRADA", chave);
                return;
            }
        } 
        printf("\nCHAVE DE BUSCA %d NAO ENCONTRADA", chave);      
    }    
}

void removeElemento(TabelaHash *th, int chave){
    int posicao = calculaHash(chave);
    if(th->tab[posicao] == NULL){
        printf("\nCHAVE DE BUSCA %d NAO ENCONTRADA", chave);
    }
    else {
        Elemento *aux, *anterior;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo){
            if (aux->valor == chave){
                if (aux == th->tab[posicao]) { //VERIFICA SE É O PRIMEIRO
                    th->tab[posicao] = th->tab[posicao]->proximo; //ATUALIZA VETOR
                } 
                else {
                    anterior->proximo = aux->proximo; 
                }
                free(aux); 
                return;
            }
            anterior = aux; 
        }
        printf("\nCHAVE DE BUSCA %d NAO ENCONTRADA", chave); 
    }   
}

void printa(TabelaHash *th){
    for(int i = 0; i < SIZE; i++){
        if (th->tab[i] == NULL){  
            printf("\nPOSICAO [%d]: []", i);    
        }
        else {
            printf("\nPOSICAO [%d]: ", i);
            Elemento *aux;
            for (aux = th->tab[i]; aux != NULL; aux = aux->proximo){ 
                printf("%d ", aux->valor); 
            }                                    
        }
    }
}

int main(){
    TabelaHash th;
    inicializaTabelaHash(&th);
    printf("\n\nTABELA VAZIA: \n");
    printa(&th);

    insereTabelaHash(&th, 7);
    insereTabelaHash(&th, 13);
    insereTabelaHash(&th, 33);
    insereTabelaHash(&th, 12);
    insereTabelaHash(&th, 5);
    insereTabelaHash(&th, 1);
    insereTabelaHash(&th, 0);
    printf("\n\nTABELA APOS INSERCOES: \n");
    printa(&th);
    
    printf("\n\nBUSCANDO ELEMENTOS: \n");
    busca(&th, 13);
    busca(&th, 8);

    removeElemento(&th, 7);
    removeElemento(&th, 13);
    removeElemento(&th, 12);
    printf("\n\nTABELA APOS REMOCOES: \n");
    printa(&th);

    return 0;
}