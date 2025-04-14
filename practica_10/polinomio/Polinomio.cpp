#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal est�ndar se puede calcular o bien con "normal_distribution" de la biblioteca "random" 
	// (versi�n 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego rest�ndole 6. M�s detalles sobre este m�todo en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no est�ndar recordemos que ser�a X = media + desviaci�n*Z, donde Z es la normal est�ndar

	float suma=0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i=0; i<12; i++) suma = suma + rand()/(float)RAND_MAX;
	return(suma-6);	
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {

	// Imprimimos el padre
    cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	SolucionParcial *hijos = new SolucionParcial[10];
	SolucionParcial menor = padre;

	// creamos 10 hijos
	for (int i = 0; i < 10; i++)
	{
		float mutacion = obtenerAleatorioNormalEstandar();

		hijos[i].x = padre.x + mutacion;
		hijos[i].y = evaluar(hijos[i].x);

		hijos[i].imprimir();

		if (abs(hijos[i].y) < abs(menor.y)) 
		{
            menor = hijos[i];
        }
	}	

	

	if (abs(menor.y) < abs(padre.y))
	{
		return obtenerRaizRecursivo(menor);
	}
	else
	{
		return padre.x;
	}
	// Calculamos la mutaci�n para cada hijo (10)  y evaluamos el polinomio para dicha mutaci�n
	// Imprimimos la solucion parcial encontrada para las mutaciones (hijo.imprimir()
	// Elegimos el mejor hijo de numeroHijos
	
	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado
}

Polinomio::Polinomio(int n, float *coeficientes) 
{

	this->n = n;
	this->coeficientes = new float[n+1];

	for (int i = 0; i < (n + 1); i++)
	{
		this->coeficientes[i] = coeficientes[i];
	}


}

float Polinomio::evaluar(float x) 
{
	float result = 0.0f;

    for (int i = 0; i <= this->n; i++) 
	{
        result += this->coeficientes[i] * pow(x, i); 
    }

    return result;
}



float Polinomio::obtenerRaiz() 
{
    SolucionParcial inicial;
    inicial.x = 0;
    inicial.y = evaluar(inicial.x);
    return obtenerRaizRecursivo(inicial);
}

// int main(void)
// {

// 	float f[] = {6, -5, 1};
// 	Polinomio pol(2, f);

// 	cout << pol.evaluar(3);
// }

Polinomio::~Polinomio() 
{
	this->n = 0;

	delete[] this->coeficientes;
}
