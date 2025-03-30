#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;



void Agenda::imprimir() 
{
	for (int i = 0; i < capacidad; i++)
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}



Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	this->nombres   = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->ocupados  = new bool[capacidad];

	for (int i = 0; i < this->capacidad; i++)
	{
		this->ocupados[i] = false;
	}
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupados;
}

int Agenda::obtenerPosicion(long telefono)
{
	return telefono % this->capacidad;
}

bool Agenda::existeContacto(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	return ((this->ocupados[posicion] && this->telefonos[posicion] == telefono) ? true : false);
}

string Agenda::getContacto(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	assertdomjudge(this->ocupados[posicion] == true && this->telefonos[posicion] == telefono)

	return this->nombres[posicion];
}

void Agenda::introducirContacto(long telefono, string contacto)
{
	int posicion = obtenerPosicion(telefono);

	assertdomjudge(ocupados[posicion] == false);

	this->ocupados[posicion] = true;
    this->telefonos[posicion] = telefono;
    this->nombres[posicion] = contacto;
}

void Agenda::eliminarContacto(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	assertdomjudge(existeContacto(telefono));

	this->ocupados[posicion] = false;
}
