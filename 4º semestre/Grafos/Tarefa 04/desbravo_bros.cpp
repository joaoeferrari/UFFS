/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Eduardo Pelegrini Ferrari
 * Matricula: 2211100012
 */

#include <iostream>
#include "Digrafo.h"
#include "Aresta.h"

using namespace std;

int main() {
    int R,C;
    //cout << "Informe o numero de regioes e o numero de canos entre eleas: \n";
    cin >> R >> C;
    Digrafo digrafo(R);

    int X,Y,D;
        for (int i = 0; i < C; i++){
            //cout << "Digite as regioes que serao conectadas e o peso da passagem: \n";
            cin >> X >> Y >> D;
            D = D * (-1);
            //cout << D;
            digrafo.instala_cano(Aresta(X,Y), D);
        }


    int O;
    //cout << "Digite quantas vezes a operacao sera realizada: \n";
    cin >> O;
        for (int i = 0; i < O; i++){
            //cout << "Informe a regiao inicial do jogo: \n";
            cin >> X;
            digrafo.max_vidas(X);
        }

    return 0;
}
