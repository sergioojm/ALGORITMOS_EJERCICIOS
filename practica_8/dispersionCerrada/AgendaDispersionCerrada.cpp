#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

void Agenda::imprimir() 
{
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	this->n = 0;
	this->nombres   = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->vacias    = new bool[capacidad];
	this->borradas  = new bool[capacidad];

	for (int i = 0; i < capacidad; i++)
	{
		this->vacias[i] = true;
		this->borradas[i] = false;
	}
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

int Agenda::obtenerPosicion(long telefono)
{
	return telefono % this->capacidad;
}

int Agenda::buscarContacto(long telefono)
{
	int posicionRelativa = this->obtenerPosicion(telefono);

	for (int i = posicionRelativa; i < this->capacidad; i++)
	{
		if (telefono == this->telefonos[i] && !this->borradas[i])
		{
			return i;
		}
	}


	return -1;
}

int Agenda::buscarHueco(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	for (int i = posicion; i < this->capacidad; i++)
	{
		if (this->vacias[i] || this->borradas[i])
		{
			return i;
		}
	}

	return -1;
}

bool Agenda::isLlena()
{
	return this->n >= this->capacidad;
}

bool Agenda::existeContacto(long telefono)
{

	int posicionRelativa = this->obtenerPosicion(telefono);

	for (int i = posicionRelativa; i < this->capacidad; i++)
	{
		if (telefono == this->telefonos[i] && !this->borradas[i] && !this->vacias[i])
		{
			return true;
		}
	}


	return false;
}

string Agenda::getContacto(long telefono)
{

	assertdomjudge(existeContacto(telefono));

	int posicionContacto = buscarContacto(telefono);
	
	// operador terciario mejor que else e if, mas estetico y directo
	return (posicionContacto == -1 ? "" : this->nombres[posicionContacto]);
	
	// a la vieja usanza, por si el domjudge se pone tonto


	// if (posicionContacto == -1) 
	// {
	// 	return "";
	// } 
	// else 
	// {
	// 	return this->nombres[posicionContacto];
	// }
}

void Agenda::introducirContacto(long telefono, string contacto)
{

	assertdomjudge(!this->isLlena());

	int huecoDisponible = this->buscarHueco(telefono);


	this->telefonos[huecoDisponible] = telefono;
	this->nombres[huecoDisponible]   = contacto;
	this->vacias[huecoDisponible]    = false;
	this->borradas[huecoDisponible]  = false;

	this->n++;

}

void Agenda::eliminarContacto(long telefono)
{

	assertdomjudge(this->existeContacto(telefono));

	int huecoDisponible = this->buscarContacto(telefono);

	this->vacias[huecoDisponible]    = true;
	this->borradas[huecoDisponible]  = true;

	this->n--;

}