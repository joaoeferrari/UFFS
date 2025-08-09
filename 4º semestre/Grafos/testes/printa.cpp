#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Grafo {
private:
    int num_vertices_;
    vector<list<int>> lista_adjacencia_;

public:
    Grafo(int num_vertices) : num_vertices_(num_vertices) {
        lista_adjacencia_.resize(num_vertices_);
    }

    void adicionarAresta(int origem, int destino) {
        lista_adjacencia_[origem].push_back(destino);
    }

    void imprime() {
        for (int i = 0; i < num_vertices_; i++) {
            cout << i << ":";
            for (int j : lista_adjacencia_[i]) {
                cout << " " << j;
            }
            cout << "\n";
        }
    }
};

int main() {
    Grafo grafo(4);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(2, 3);

    grafo.imprime();

    return 0;
}
