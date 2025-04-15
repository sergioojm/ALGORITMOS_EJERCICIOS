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

            int color = 0;
            if (i % 2 == 0) color = 1;
            else color = 2;

            // 1 = rojo
            // 2 = blanco

            adyaciencia->rellenarArista(aristaInit, aristaFinn, color);
        }
        
        // comprobar si alguna arista conecta mas de una vez el mismo nodo

        adyaciencia->mostrarMatriz();

        if (adyaciencia->esBipartito())
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