#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" 

using namespace std;

void Agenda::imprimir() 
{
	for (int i=0; i<capacidad; i++) 
	{
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}


Agenda::Agenda(int capacidad) {
	
	this->capacidad = capacidad;
	this->n = 0;
	this->tabla = (ListaEnlazada*) malloc(sizeof(ListaEnlazada) * capacidad);
}


Agenda::~Agenda() 
{
	free(this->tabla);
}


int Agenda::obtenerPosicion(long telefono) 
{
	return telefono % this->capacidad;
}


bool Agenda::existeContacto(long telefono) 
{
	Contacto contacto;
	contacto.telefono = telefono;

	if (this->tabla[obtenerPosicion(telefono)].buscar(contacto) != -1) 
	{
		return true;
	}

	return false;
}


string Agenda::getContacto(long telefono) 
{
	
	assertdomjudge(existeContacto(telefono));

	int posicion = obtenerPosicion(telefono);
	

	for (int i = 0; i < this->tabla[posicion].getN(); i++) 
	{
		if (this->tabla[posicion].getValor(i).telefono == telefono) 
		{
			return this->tabla[posicion].getValor(i).nombre;
		}
	}

	return "";
}


void Agenda::introducirContacto(long telefono, string contacto) 
{
	
	assertdomjudge(!existeContacto(telefono));

	Contacto myContact;
	myContact.telefono = telefono;
	myContact.nombre = contacto;

	this->tabla[obtenerPosicion(telefono)].insertar(0, myContact);

	this->n++;
}


void Agenda::eliminarContacto(long telefono) 
{
	
	assertdomjudge(existeContacto(telefono));

	int posicion = obtenerPosicion(telefono);

	for (int i = 0; i < this->tabla[posicion].getN(); i++) 
	{
		if (this->tabla[posicion].getValor(i).telefono == telefono) 
		{
			this->tabla[posicion].eliminar(i);
		}
	}

	this->n--;
}