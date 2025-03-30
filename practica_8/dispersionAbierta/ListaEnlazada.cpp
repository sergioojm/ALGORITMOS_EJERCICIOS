#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;


Nodo *ListaEnlazada::getNodo(int posicion) 
{
    assertdomjudge(posicion >= 0 && posicion < n );

    Nodo *nodo = this->lista;

    for (int i = 0; i < posicion; i++) 
    {
        nodo = nodo->siguienteNodo;
    }

    return nodo;
}


ListaEnlazada::ListaEnlazada() 
{
    this->lista = NULL;
    this->n = 0;
}


ListaEnlazada::~ListaEnlazada() 
{
    Nodo *actual = this->lista;

    while (actual != nullptr)
    {
        Nodo *temp = actual;
        actual = actual->siguienteNodo;
        delete temp;
    }
}


int ListaEnlazada::getN() 
{
    return this->n;
}


Contacto ListaEnlazada::getValor(int posicion) 
{
    assertdomjudge(posicion >= 0 && posicion < getN());

    Nodo *nodo = getNodo(posicion);
    return nodo->elemento;
}


void ListaEnlazada::setValor(int posicion, Contacto nuevoValor) 
{
    assertdomjudge(posicion >= 0 && posicion < getN());

    Nodo *nodo = getNodo(posicion);
    nodo->elemento = nuevoValor;
}


void ListaEnlazada::insertar(int posicion, Contacto nuevoValor) 
{
    assertdomjudge(posicion >= 0 && posicion <= getN());

    Nodo *temp;
    Nodo *nodo = new Nodo();
    nodo->elemento = nuevoValor;

    if (posicion == 0) 
    {
        nodo->siguienteNodo = lista;
        lista = nodo;
    } 
    else 
    {
        temp = getNodo(posicion - 1);
        nodo->siguienteNodo = temp->siguienteNodo;
        temp->siguienteNodo = nodo;
    }

    this->n++;
}


void ListaEnlazada::eliminar(int pos)
{
    assertdomjudge(pos >= 0 && pos < this->n);

    Nodo *eliminarNodo = nullptr;

    if (pos == 0)
    {
        this->lista = this->lista->siguienteNodo;
    }
    else
    {
        Nodo *anterior = this->getNodo(pos - 1);

        eliminarNodo = anterior->siguienteNodo;
        anterior->siguienteNodo = eliminarNodo->siguienteNodo;
    
    }

    delete eliminarNodo;
    this->n--;
}


void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) 
{
    int i = 0;

    while (i < listaAConcatenar->getN()) 
    {
        insertar(getN(), listaAConcatenar->getValor(i));
        i++;
    }
}


int ListaEnlazada::buscar(Contacto elementoABuscar)
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->getValor(i).telefono == elementoABuscar.telefono)
        {
            return i;
        }
    }

    return -1; 
}
