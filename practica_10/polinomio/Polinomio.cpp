#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal estándar se puede calcular o bien con "normal_distribution" de la biblioteca "random" (versión 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego restándole 6. Más detalles sobre este método en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no estándar recordemos que sería X = media + desviación*Z, donde Z es la normal estándar

	float suma=0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i=0; i<12; i++) suma = suma + rand()/(float)RAND_MAX;
	return(suma-6);	
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {

	// Imprimimos el padre
        cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	// Calculamos la mutación para cada hijo (10)  y evaluamos el polinomio para dicha mutación
	// Imprimimos la solucion parcial encontrada para las mutaciones (hijo.imprimir()
	// Elegimos el mejor hijo de numeroHijos
	
	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado

	
}

Polinomio::Polinomio(int n, float *coeficientes) {


}

float Polinomio::evaluar(float x) {

}


float Polinomio::obtenerRaiz() {

}


Polinomio::~Polinomio() {

}
