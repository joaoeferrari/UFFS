#include "Grafo.h"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo:: num_vertices() {
    return num_vertices_;
}

int Grafo:: num_arestas() {
    return num_arestas_;
}

void Grafo::inserir_aresta(Aresta e) {
    if((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;
    
        num_arestas_++;
    }
}

void Grafo::remover_aresta(Aresta e) {
    if(matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;
    
        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (int j = 0; j < num_vertices_; j++){
            if (matriz_adj_[i][j] != 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
}

bool Grafo::caminho(int v, int w, std::vector<int> marcado) {
    if (v == w) {
        printf("%d-", v);
        return true;
    }
    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++){
        if (matriz_adj_[v][u] != 0){
            if (marcado[u] == 0){
                if (caminho(u, w, marcado)){
                    printf("%d-", v);
                    cout << "Existe caminho" << endl;
                    return true;
                }else{
                    cout << "Nao existe caminho" << endl;
                }
            }
        }
    }
    return false;
}

/*
bool Graph::verify_related()
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (i <= j)
                continue;
            int marked[vertices_number_] = {0};
            if (!getPath(i, j, marked))
                return false;
        }
    }
    return true;
}
*/

void Grafo::busca_prof(int v) {
    std::vector <int> marcado = {0};
    stack<int> pilha;
    pilha.push(v);
    while (!pilha.empty()) {
        int w = pilha.top();
        pilha.pop();
        if (marcado[w] == 0) {
            printf("%d\n", w);
            marcado[w] = 1;
            for (int u = (num_vertices_ - 1); u >= 0; u--){
                    if (matriz_adj_[w][u] != 0){
                        if (marcado[u] == 0){
                                pilha.push(u);
                        }
                    }
            }
        }
    }
}   



 void Grafo::busca_larg(int v, int pai[], int dist[]) {
    std::vector <int> marcado = {0};
    pai = {0}, dist = {0};
    queue<int> fila;
    marcado[v] = 1;
    pai[v] = -1;
    dist[v] = 0;
    fila.push(v);
    while (!fila.empty()) {
    int w = fila.front();
    fila.pop();
    printf("%d\n", w);
        for (int u = 0; u < num_vertices_; u++){
            if (matriz_adj_[w][u] != 0){
                    if (marcado[u] == 0) {
                        marcado[u] = 1;
                        pai[u] = w;
                        dist[u] = dist[w] + 1;
                        fila.push(u);
                    }
            } 
        } 
    }
 }
