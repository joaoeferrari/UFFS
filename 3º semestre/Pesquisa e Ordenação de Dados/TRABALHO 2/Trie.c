/**
 * @file Trie.c
 * @author João Eduardo Pelegrini Ferrari
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 03 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma estrutura de Trie para armazenar chaves em formato de
 * caractere. Inclua operações de inserção, remoção e busca completa e busca
 * parcial na estrutura do Trie.
 *      Para a busca completa, o algoritmo deve apenas informar se a chave foi
 * encontrada ou não dentro da estrutura. Para a busca parcial, o algoritmo deve
 * retornar todas as chaves armazenadas abaixo da string informada para a busca.
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TamAlfabeto 26

typedef struct NoTrie {
    struct NoTrie* filhos[TamAlfabeto];
    int finalPalavra;
} NoTrie;

NoTrie* criarNo() {
    NoTrie* no = (NoTrie*)malloc(sizeof(NoTrie));
    no->finalPalavra = 0;
    for (int i = 0; i < TamAlfabeto; i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

void inserir(NoTrie* raiz, const char* chave) {
    NoTrie* NoAtual = raiz;
    int tam = strlen(chave);
    for (int nivel = 0; nivel < tam; nivel++) {
        int indice = chave[nivel] - 'a';
        if (NoAtual->filhos[indice] == NULL) {
            NoAtual->filhos[indice] = criarNo();
        }
        NoAtual = NoAtual->filhos[indice];
    }
    NoAtual->finalPalavra = 1;
}

int buscar(NoTrie* raiz, const char* chave) {
    NoTrie* NoAtual = raiz;
    int tam = strlen(chave);
    for (int nivel = 0; nivel < tam; nivel++) {
        int indice = chave[nivel] - 'a';
        if (NoAtual->filhos[indice] == NULL) {
            return 0; // NÃO ENCONTROU A CHAVE
        }
        NoAtual = NoAtual->filhos[indice];
    }
    return NoAtual != NULL && NoAtual->finalPalavra;
}

void buscarPrefixoValido(NoTrie* no, char* prefixo, int nivel, void (*callback)(const char*)) {
    if (no->finalPalavra) {
        prefixo[nivel] = '\0';
        callback(prefixo);
    }
    for (int i = 0; i < TamAlfabeto; i++) {
        if (no->filhos[i] != NULL) {
            prefixo[nivel] = i + 'a';
            buscarPrefixoValido(no->filhos[i], prefixo, nivel + 1, callback);
        }
    }
}

void buscarPrefixo(NoTrie* raiz, const char* prefixo, void (*callback)(const char*)) {
    NoTrie* NoAtual = raiz;
    int tam = strlen(prefixo);
    char* prefixoTemp = (char*)malloc((tam + 1) * sizeof(char));
    for (int nivel = 0; nivel < tam; nivel++) {
        int indice = prefixo[nivel] - 'a';
        if (NoAtual->filhos[indice] == NULL) {
            return; // NÃO ENCONTROU PREFIXO
        }
        NoAtual = NoAtual->filhos[indice];
        prefixoTemp[nivel] = prefixo[nivel];
    }
    prefixoTemp[tam] = '\0';
    buscarPrefixoValido(NoAtual, prefixoTemp, tam, callback);
    free(prefixoTemp);
}

NoTrie* excluirChave(NoTrie* raiz, const char* chave, int nivel) {
    if (raiz == NULL) {
        return NULL;
    }
    if (chave[nivel] == '\0') {
        if (raiz->finalPalavra) {
            raiz->finalPalavra = 0;
        }
        if (Vazio(raiz)) {
            free(raiz);
            raiz = NULL;
        }
        return raiz;
    }
    int indice = chave[nivel] - 'a';
    raiz->filhos[indice] = excluirChave(raiz->filhos[indice], chave, nivel + 1);
    if (Vazio(raiz) && !raiz->finalPalavra) {
        free(raiz);
        raiz = NULL;
    }
    return raiz;
}

int Vazio(NoTrie* no) {
    for (int i = 0; i < TamAlfabeto; i++) {
        if (no->filhos[i] != NULL) {
            return 0; // AO MENOS UM FILHO
        }
    }
    return 1; // NENHUM FILHO
}

void printPalavra(const char* palavra) {
    printf("%s\n", palavra);
}

void printTrie(NoTrie* raiz, char* prefixo, int nivel) {
    if (raiz->finalPalavra) {
        prefixo[nivel] = '\0';
        printPalavra(prefixo);
    }
    for (int i = 0; i < TamAlfabeto; i++) {
        if (raiz->filhos[i] != NULL) {
            prefixo[nivel] = i + 'a';
            printTrie(raiz->filhos[i], prefixo, nivel + 1);
        }
    }
}

void liberarTrie(NoTrie* raiz) {
    if (raiz == NULL) {
        return;
    }
    for (int i = 0; i < TamAlfabeto; i++) {
        liberarTrie(raiz->filhos[i]);
    }
    free(raiz);
}

int main() {
    NoTrie* raiz = criarNo();

    inserir(raiz, "amy");
    inserir(raiz, "ann");
    inserir(raiz, "emma");
    inserir(raiz, "rob");
    inserir(raiz, "roger");
    inserir(raiz, "robert");
    inserir(raiz, "bob");
    inserir(raiz, "emmily");

    // BUSCA DE PALAVRAS COMPLETAS
    printf("Buscando palavras completas:\n");
    printf("'amy': %s\n", buscar(raiz, "amy") ? "Encontrada" : "Não encontrada");
    printf("'robert': %s\n", buscar(raiz, "robert") ? "Encontrada" : "Não encontrada");
    printf("'pedro': %s\n", buscar(raiz, "pedro") ? "Encontrada" : "Não encontrada");

    // BUSCA PELO PREFIXO
    printf("\nBuscando palavras por prefixo 'rob':\n");
    buscarPrefixo(raiz, "rob", printPalavra);

    // EXCLUIR A PALAVRA
    raiz = excluirChave(raiz, "ammy", 0);

    // IMPRIME TODAS AS PALAVRAS 
    printf("\nImprimindo todas as palavras da Trie:\n");
    char prefixo[100];
    printTrie(raiz, prefixo, 0);

    // LIBERA MEMÓRIA
    liberarTrie(raiz);

    return 0;
}