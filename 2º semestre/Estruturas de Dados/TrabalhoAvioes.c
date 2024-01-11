//Aluno: João Eduardo Pelegrini Ferrari
//Matrícula: 2211100012


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Id;
typedef char Name [30];

typedef struct Aviao {
Id identificador;
Name nome; 
struct Aviao *proximo;
}aviao; //STRUCT DO NODO

typedef struct {
    aviao *primeiro;
    aviao *ultimo;
}Fila; //STRUCT DA FILA (PONTEIROS)

Fila *fila; //GERAL



//ADICINAR UM AVIÃO A FILA DE DECOLAGEM

void AdicionaAviao(Fila *fila, Id identificador, Name nome) {
    aviao *aux;
    aux = malloc(sizeof(aviao));
    aux->identificador = identificador;
    strcpy(aux->nome, nome);
    aux->proximo = NULL;
    if (fila->primeiro == NULL){
        fila->primeiro = aux;
        fila->ultimo = aux;
    }else{
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
    printf("\n------------------------------------------\n");
    printf("ADICIONANDO AVIAO NA FILA DE DECOLAGEM:\n");
    printf("NOME: %s\nID:%d", nome, identificador);
    printf("\n------------------------------------------\n");
}
    

//AUTORIZAR A DECOLAGEM DO PRIMEIRO AVIÃO DA FILA (REMOVER)

void removeAviao(Fila *fila) {
    aviao *aux;

    //*identificador = fila->primeiro->identificador;
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo){
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }else{
        fila->primeiro = fila->primeiro->proximo;
    }
    printf("AUTORIZANDO A DECOLAGEM DO AVIAO A SEGUIR:\nNOME:%s\nID:%d\n\n",aux->nome, aux->identificador);
    free(aux);
    
}

//LISTAR O NÚMERO DE AVIÕES AGUARDANDO NA FILA DE DECOLAGEM

int contAvioes(Fila *fila){
    aviao *aux;
    int contador = 0;
    for (aux = fila->primeiro; aux != NULL; aux = aux->proximo){
        contador = contador + 1;
    }
    printf("\n");
    printf("NUMERO DE AVIOES NA FILA DE DECOLAGEM: %d\n", contador);
    printf("\n");
    return contador;
}

//LISTAR TODOS OS AVIÕES NA FILA DE DECOLAGEM

void Listagem (Fila *fila){
    aviao *aux;
    if (fila->primeiro==NULL){
        printf("NENHUM AVIAO NA FILA DE DECOLAGEM");
        return 0;
    }
    printf("\nLISTAGEM DOS AVIOES NA FILA:");
    for (aux = fila->primeiro; aux != NULL; aux = aux->proximo){
        printf("\n======================================\n");
        printf("NOME: %s\n", aux->nome);
        printf("ID: %d\n", aux->identificador);
        printf("======================================\n");
    }
}

//LISTAR AS INFORMAÇÕES DO PRIMEIRO ELEMENTO DA FILA

void ListagemPrimeiro(Fila *fila){
    aviao *aux;
    if (fila->primeiro==NULL){
        printf("NENHUM AVIAO NA FILA DE DECOLAGEM\n");
        return 0;
    }
    aux = fila->primeiro;
    printf("INFORMACOES DO PRIMEIRO AVIAO DA FILA:\n");
    printf("NOME: %s\n", aux->nome);
    printf("ID: %d\n\n", aux->identificador);
    
}


void inicializaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}
int filaVazia(Fila *fila) {
    return (fila->primeiro == NULL);
}
    
    

int main() {
    Fila fila;
    Id identificador;
    Name nome;

    printf("\n*****************************\n");
    printf("CONTROLE PISTA DE DECOLAGEM\n");
    printf("******************************\n");


    //INCIALIZANDO A FILA
    inicializaFila(&fila);

    //TESTE SEM NENHUM AVIAO
    ListagemPrimeiro(&fila);

    Listagem(&fila);
    

    //ADICIONANDO AVIOES
    AdicionaAviao(&fila, 1, "PRIMEIRO AVIAO");
    AdicionaAviao(&fila, 2, "SEGUNDO AVIAO");
    AdicionaAviao(&fila, 3, "TERCEIRO AVIAO");

    //LISTAGEM
    Listagem(&fila);

    //NUMERO DE AVIOES DA FILA
    contAvioes(&fila);
    
    //LISTAGEM PRIMEIRO
    ListagemPrimeiro(&fila);

    removeAviao(&fila);

    contAvioes(&fila);

    Listagem(&fila);

    removeAviao(&fila);

    ListagemPrimeiro(&fila);

    Listagem(&fila);
    


    return 0;
}