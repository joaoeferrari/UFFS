#ifndef GRAFO_H

#define GRAFO_H

#include <vector>
#include "Aresta.h"

class Grafo {
public:
  ;
    // Constroi um grafo simples que possui o numero de vertices recebido por parametro e que não possui arestas
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    //Insere uma aresta no grafo caso a aresta não exista no grafo e não seja um laço, deixando o grafo simples
    void inserir_aresta(Aresta e);
    //Remova uma aresta do grafo caso ela exista
    void remover_aresta(Aresta e);

    void caminho(int v, int w, std::vector<int> marcado);
    void busca_larg(int v, int pai[], int dist[]);
    void busca_prof(int v);

  
    
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_; //vector é uma classe, "destrutor/free"//MUDAR PRA LIST NO LUGAR DE  SEGUNDO VECTOR - TRA
  //  std::vector<std::vector<int>>marcado;

};

#endif /* GRAFO_H */
