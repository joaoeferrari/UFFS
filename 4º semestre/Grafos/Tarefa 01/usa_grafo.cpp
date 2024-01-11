/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegriini Ferrari
 * Matricula: 2211100012
 */
#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int main() {

   try {
        int numVertices, numOperacoes;
        //cout << "Digite o numero de vertices do grafo e em seguida a quantidade de operacoes: ";
        cin >> numVertices >> numOperacoes;
        Grafo grafo(numVertices); //construtor
        
        int contador = 1;
        char operacao;
        int x, y, v;
        while (contador <= numOperacoes){
           //cout << "Informe a operacao: ";
            cin >> operacao;

                if (operacao == 'I'){
                    //cout << "Digite os vertices que a aresta sera adicionada: ";
                    cin >> x >> y;
                    grafo.insere_aresta(Aresta(x,y));
                }

                if (operacao == 'R'){
                    //cout << "Digite os vertices que a aresta sera removida: ";
                    cin >> x >> y;
                    grafo.remove_aresta(Aresta(x,y));
                }

                if (operacao == 'E'){  //obtem num arestas
                    cout << grafo.num_arestas() << endl;
                }

                if (operacao == 'Q'){
                    //cout << "Digite o vertice que sera removido: ";
                    cin >> v;
                    grafo.remove_vertice(v);
                }
                
                if (operacao == 'N'){ //obtem num vertices
                    cout << grafo.num_vertices() << endl;
                }

                if (operacao == 'P'){
                    grafo.imprime();
                }

            contador++;
        }
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}