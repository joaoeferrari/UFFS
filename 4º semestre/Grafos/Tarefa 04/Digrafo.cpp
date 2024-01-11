/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */
#include "Digrafo.h"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

Digrafo::Digrafo(int num_vertice){
    num_vertices_ = num_vertice;
    num_arestas_ = 0;
    lista_adj_.resize(num_vertice); //garantir que a lista tenha espaço suficiente
    for(int i = 0; i < num_vertice; i++){
        lista_adj_[i].clear(); //limpando as listas
    }
}

void Digrafo::instala_cano(Aresta a, int p){
    bool existeCaminho = false;
    if (a.v1 == a.v2 || a.v1 >= num_vertices_ || a.v2 >= num_vertices_) { //duplicata e limite
        return;
    } 

   for (const auto& i : lista_adj_[a.v1]) { //percorre todas as arestas em v1
    if (i.first == a.v2 || i.second == a.v2) {
        existeCaminho = true;
        return;
        }    
    }
    if (existeCaminho == false) {
        lista_adj_[a.v1].push_back(std::make_pair(a.v2,p)); //direcao aresta e peso
        //cout << "Aresta adicionada em v1 com peso " << p <<endl;
    }
}

void Digrafo::max_vidas(int x) {//Bellman-ford
   //vector<int> pai(num_vertices_, -1); //inicializa cada um com -1
   vector<int> dp(num_vertices_, INT_MAX); //valor maximo de um inteiro
   dp[x] = 0;

    for(int i = 0; i < num_vertices_ - 1; i++){ 
        for(int j = 0; j < num_vertices_; j++){ //percorre vertices do grafo - relaxamento
            for(const auto& a : lista_adj_[j]){ 
                
                if (dp[j] != INT_MAX && dp[a.first] > dp[j] + a.second) { //second = peso
                    dp[a.first] = dp[j] + a.second;
                   // pai[a.first] = j;
                }
            }
        }
    }

    for(int j = 0; j < num_vertices_; j++) {
        for (const auto& a : lista_adj_[j]) { 
            
            if (dp[j] != INT_MAX && dp[a.first] > dp[j] + a.second) { //ciclo de peso negativo
                cout << x << ": ilimitada\n";
                return;
            }
        }
    }

    int vidas = 0;
    for (int i = 0; i < num_vertices_; i++) {
        vidas = max(vidas, dp[i]*(-1)); //funcao max para retornar o maior valor encontrado
    }

    cout << x << ": " << vidas << endl;
}







