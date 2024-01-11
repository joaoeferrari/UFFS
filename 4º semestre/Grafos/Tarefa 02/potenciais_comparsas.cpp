/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */
#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int main() {
    int P,L, X, Y;
    //cout << "Digite o numero de pessoas do grupo e a quantidade de ligacoes: \n";
    cin >> P >> L;
    Grafo grafo(P); //construtor
    
    int contador = 1;
    char T;

    while (contador <= L){
        //cout << "Informe as duas pessoas envolvidas na ligacao e o turno: \n";
        cin >> X >> Y >> T;
        if (T == 'W'){
            grafo.adiciona_comparsa(Aresta(X,Y));
        }
        contador++;
    }
    int O;
    //cout << "Digite quantas vezes sera realizada a operacao: \n";
    cin >> O;
    
    for (int i = 0; i < O; i++){
        //cout << "Informe a pessoa que gostaria de saber os seus potenciais comparsas: \n";
        cin >> X;
        grafo.delacao(X);
    }

    return 0;
}
