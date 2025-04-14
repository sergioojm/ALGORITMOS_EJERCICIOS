#include "Matriz.h"
#include <iostream>

using namespace std;

int main(void)
{
    Matriz *adyaciencia = nullptr;

    int numVertices = 0;
    int numAristas  = 0;

    while(true)
    {
        cin >> numVertices;

        if (numVertices == 0) break;

        cin >> numAristas;

        adyaciencia = new Matriz(numVertices, numVertices);

        for (int i = 0; i < numAristas; i++)
        {
            int aristaInit = 0;
            int aristaFinn = 0;

            cin >> aristaInit;
            cin >> aristaFinn;

            adyaciencia->rellenarArista(aristaInit, aristaFinn);
        }
        
        // comprobar si alguna arista conecta mas de una vez el mismo nodo
        if (adyaciencia->comprobarAtleti())
        {
            cout << "SI" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}