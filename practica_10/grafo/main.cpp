#include "Vertice.h"
#include <iostream>
#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}

using namespace std;

int main(void)
{
    Vertice *grafo = nullptr;

    int numVertices = 0;
    int numAristas  = 0;
    int salir = false;
    

    while(!salir)
    {
        cin >> numVertices;

        
        if (numVertices <= 0) 
        {
            salir = true;
        }
        else
        {
            assertdomjudge(numVertices>=1 && numVertices<=100);

            cin >> numAristas;
    
            grafo = new Vertice[numVertices];
    
            // crear grafo
            for (int i = 0; i < numVertices; i++)
            {

                grafo[i].color = 0;
                grafo[i].hijos = new Vertice[numVertices];
            }
    
            // obtener aristas
            for (int i = 0; i < numAristas; i++)
            {
                int aristaVerticePadre = 0;
                int aristaVerticeHijo  = 0;
    
                cin >> aristaVerticePadre;
                cin >> aristaVerticeHijo;
    
                assertdomjudge(aristaVerticePadre != aristaVerticeHijo);
                assertdomjudge(aristaVerticePadre >= 0 && aristaVerticePadre < numVertices 
                    && aristaVerticeHijo >= 0 && aristaVerticeHijo <= numVertices);
                assertdomjudge(grafo[aristaVerticePadre].hijos[aristaVerticeHijo].color == 0 
                    && grafo[aristaVerticeHijo].hijos[aristaVerticePadre].color == 0);
                

                int color = (aristaVerticePadre % 2 == 0) ? 1 : 2;
                int colorHijo = (aristaVerticeHijo % 2 == 0) ? 1 : 2;

    
                grafo[aristaVerticePadre].color = color;
                grafo[aristaVerticeHijo].color = colorHijo;
    
                grafo[aristaVerticePadre].hijos[aristaVerticeHijo].color = grafo[aristaVerticeHijo].color;
                grafo[aristaVerticeHijo].hijos[aristaVerticePadre].color = grafo[aristaVerticePadre].color;
            }
            
            // comprobar si alguna arista conecta mas de una vez el mismo nodo
            bool result = true;
           
            //cout << "calculando" << endl;
            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    if (grafo[i].color == grafo[i].hijos[j].color)
                    {
                        // cout << i << " " << j << endl;
                        // cout << "color padre " << grafo[i].color << " color hijo" <<  grafo[i].hijos[j].color << endl;
                        result = false;
                    }
                }
            }
    
            if (result)
            {
                cout << "SI" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
      
    for (int i = 0; i < numVertices; i++)
    {
        delete[] grafo->hijos;
    }
    delete[] grafo;

    return 0;
}
