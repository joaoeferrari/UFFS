/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */

#ifndef GRAFO_H
#include <vector>
#include <list>
#include "Aresta.h"

#define GRAFO_H

class Grafo {
public:
    Grafo (int num_vertices);

    void adiciona_comparsa(Aresta a);
    void investigacao(int v, int dist[]);
    void delacao(int x); 


private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>>lista_adj_; 
};

#endif /* GRAFO_H */
