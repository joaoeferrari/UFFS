/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */

#ifndef DIGRAFO_H
#include <vector>
#include <list>
#include "Aresta.h"

#define DIGRAFO_H

class Digrafo {
    public:
        Digrafo (int num_vertices);

        
        void instala_cano(Aresta a, int d);
        void max_vidas(int x);
        //void imprime(int x);
        
    private:
        int num_vertices_;
        int num_arestas_;
        std::vector<std::list<std::pair<int,int>>> lista_adj_; //armazena vertice e peso

};

#endif /* DIGRAFO_H */
