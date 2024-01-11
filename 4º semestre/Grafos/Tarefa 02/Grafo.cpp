/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */

#include "Grafo.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

Grafo::Grafo(int num_vertices){
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices); 
    for (int i=0; i<num_vertices; i++){
        lista_adj_[i].clear(); 
    }
}

void Grafo::adiciona_comparsa(Aresta a){
    bool existeComparsa = false;
    if (a.v1 == a.v2 || a.v1 >= num_vertices_ || a.v2 >= num_vertices_) { //duplicata e limite
        return;
    } 

    for(std::list<int>::iterator it = lista_adj_[a.v1].begin(); it != lista_adj_[a.v1].end(); it++) {
        if (*it == a.v2){
            existeComparsa = true;
            return;
        } 
    }

    if (existeComparsa == false){
        lista_adj_[a.v1].push_back(a.v2);
        lista_adj_[a.v2].push_back(a.v1);
    } 
}

void Grafo::delacao(int x){
    std::vector<int> distancia(num_vertices_); //definicao tamanho
    
    investigacao(x, distancia.data());//busca larg

    cout << x << ": ";
    for (int i=0; i<num_vertices_;i++){
        if (distancia[i]> 0 && distancia[i] <= 3){//verificacao condicoes a partir da busca larg
            cout << i << " ";
        }
    }
    cout << "\n";

}
   
void Grafo::investigacao(int v, int distancia[]) {
    vector<int> marcado(num_vertices_, 0); 
    queue<int> fila;

    marcado[v] = 1;
    distancia[v] = 0;
    fila.push(v);

    while (!fila.empty()) {
        int w = fila.front();
        fila.pop();

        for (int u : lista_adj_[w]) {
            if (marcado[u] == 0) {
                marcado[u] = 1;
                distancia[u] = distancia[w] + 1;
                fila.push(u);
                
            }
        }
    }
}

