#include <iostream>
#include <cstdlib>

#define MAX 100
#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}

using namespace std;

bool esBipartito(int grafo[MAX][MAX], int numVertices) 
{
    int color[MAX] = {0};  // 0: sin color, 1: rojo, 2: blanco
    int cola[MAX];         
    int frente, fin;

    // BFS
    // https://es.wikipedia.org/wiki/Búsqueda_en_anchura
    
    for (int inicio = 0; inicio < numVertices; inicio++) 
    {
        if (color[inicio] == 0) 
        {
           
            frente = fin = 0;
            cola[fin++] = inicio;
            color[inicio] = 1; 

            while (frente < fin) 
            {
                int actual = cola[frente++];

                for (int vecino = 0; vecino < numVertices; vecino++) 
                {
                    if (grafo[actual][vecino]) 
                    {
                        if (color[vecino] == 0) 
                        {
                            color[vecino] = (color[actual] == 1) ? 2 : 1;
                            cola[fin++] = vecino;
                        } 
                        else if (color[vecino] == color[actual]) 
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main(void) 
{
    int numVertices, numAristas;

    while (cin >> numVertices && numVertices > 0) 
    {
        assertdomjudge(numVertices >= 1 && numVertices <= 100);

        cin >> numAristas;

        int grafo[MAX][MAX] = {0};

        for (int i = 0; i < numAristas; i++) 
        {
            int v1, v2;
            cin >> v1 >> v2;

            assertdomjudge(v1 != v2);
            assertdomjudge(v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices);
            assertdomjudge(grafo[v1][v2] == 0);

            grafo[v1][v2] = 1;
            grafo[v2][v1] = 1;
        }

        if (esBipartito(grafo, numVertices)) 
        {
            cout << "SI" << endl;
        } else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
