#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int main() {
    try {
        std::vector<int> marcado = {0};

        Grafo grafo(5);

        Aresta e(3, 4);
        grafo.inserir_aresta(e);

        //grafo.inserir_aresta(Aresta(4, 2));
        

        grafo.caminho(3, 4, marcado);

        // grafo.imprime();
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
