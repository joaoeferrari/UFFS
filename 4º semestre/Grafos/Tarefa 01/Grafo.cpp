/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegriini Ferrari
 * Matricula: 2211100012
 */

#include "Grafo.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

Grafo::Grafo(int num_vertices){
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices); //criação das listas com base no numero de vertices
    for (int i=0; i<num_vertices; i++){
        lista_adj_[i].clear(); //zerando as listas
    }
}

int Grafo::num_vertices(){
    return num_vertices_;
}

int Grafo::num_arestas(){
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta a){
    bool existeAresta = false;
    if (a.v1 == a.v2 || a.v1 >= num_vertices_ || a.v2 >= num_vertices_) { //duplicata e limite
        return;
    } 

    for(std::list<int>::iterator it = lista_adj_[a.v1].begin(); it != lista_adj_[a.v1].end(); it++) {
        if (*it == a.v2){
            existeAresta = true;
            return;
        } 
    }

    if (existeAresta == false){
        lista_adj_[a.v1].push_front(a.v2);
        lista_adj_[a.v2].push_front(a.v1);

        //cout << "Aresta adicionada" << endl;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta a) { 
   for(std::list<int>::iterator it = lista_adj_[a.v1].begin(); it != lista_adj_[a.v1].end(); it++) {
        if (*it == a.v2){
            lista_adj_[a.v1].remove(a.v2);
            lista_adj_[a.v2].remove(a.v1);

            //cout << "Aresta removida" << endl;

            num_arestas_--;
            break;
        }
        
        
    }
}

void Grafo::imprime() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (int v : lista_adj_[i]) {
            cout << " " << v;
        }
        cout << endl;
    }
}

void Grafo::remove_vertice(int v) {
    if (v < 0 || v >= lista_adj_.size()) { 
        return;
    }
   
    for (int it : lista_adj_[v]) {  //exclui arestas ver
        lista_adj_[it].remove(v);
        num_arestas_--;
    }

    
    lista_adj_.erase(lista_adj_.begin() + v); //exclui ver

    //cout << "Vertice removido" << endl;

    num_vertices_--;

    
    for (std::list<int>& i : lista_adj_) { //atualiza indices
        for (int& th : i) { 
            if (th > v) {
                th--;
            }
        }
    }
}
