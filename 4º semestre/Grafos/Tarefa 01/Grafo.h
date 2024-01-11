/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:João Eduardo Pelegriini Ferrari
 * Matricula: 2211100012
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <list>
#include <vector>
#include <algorithm>


class Grafo {
public:
    Grafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta a);
    void remove_aresta(Aresta a);
    void remove_vertice(int v);
    void imprime();

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>>lista_adj_; 

};

#endif /* GRAFO_H */
