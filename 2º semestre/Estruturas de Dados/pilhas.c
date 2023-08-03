#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elemPilha
{
    Item item;
    struct elemPilha *proximo;
}ElemPilha;

typedef struct 
{
    ElemPilha *topo;
}Pilha;



//TODAS AS OPERAÇÕES SÃO FEITAS NO INICIO PORQUE É UMA PILHA (LIFO)

//FUNÇÃO PARA INSERIR 
void inserePilha(Pilha *pilha, Item item){
    ElemPilha *aux;
    aux = malloc(sizeof(ElemPilha));
    aux->item = item;

    aux->proximo = pilha->topo;//! O proximo do auxuliar vai apontar pro topo da pilha
    pilha->topo = aux;//! o topo da pilha vai virar o novo item
}

void removerPilha(Pilha *pilha, Item *item){//Por que passou o item como ponteiro? porque eu to passando endereço
    ElemPilha *aux;
    //verificar se a pilha está vazia
    if (pilha == NULL){
        return;
    }
    *item = pilha->topo->item; //armazenando o item que vai ser excluido em um ponteiro para não perder o encadeamento

    aux = pilha->topo;//! armazeno no auxiliar o item que ue vou remover
    pilha->topo = pilha->topo->proximo;//! o topo da pilha que antes era o item vira o proximo dele

    free(aux);
}

void inicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha){
    return(pilha->topo)==NULL;
}

void liberaPilha(Pilha *pilha){
    ElemPilha *aux;
    while(pilha->topo != NULL){
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        free(aux);
    }
}

int main(){
    Pilha pilha;//Inicialização da Pilha e do Item - declarando variavel pilha(que é o ponteiro pro topo)
    Item item;//



inicializaPilha(&pilha);

for (int i=0; i<10;i++){
    item = i;
    printf("INSERINDO NA PILHA O ITEM %d.\n", item);
    inserePilha(&pilha,item);
}

while (pilhaVazia(&pilha)==0)
{
    removerPilha(&pilha,&item);
    printf("ITEM %d REMOVIDO DA PILHA. \n", item);
}
    liberaPilha(&pilha);
    return 0;
}

// PRATICA PROVA
//inserção ocorre no inicio (topo da pilha)


// void InserePilhaTeste(Pilha *pilha, Item item){
//     ElemPilha *aux;
//     aux = malloc(sizeof(ElemPilha));
//     aux->item = item;
//     aux->proximo = pilha->topo;
//     pilha->topo = aux;
    
// }

// void RemoverPilhaTeste(Pilha *pilha, Item *item){
//     ElemPilha *aux;

//     if (pilha == NULL){
//         return;
//     }
//     *item = pilha->topo->item;

//     aux = pilha->topo;
//     pilha->topo = pilha->topo->proximo;

//     free(aux);


// }