#include "ListaEnlazada.h"
#include <iostream>


#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaEnlazada::ListaEnlazada()
{
    this->lista = nullptr;
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

Nodo *ListaEnlazada::getNodo(int pos)
{
    assertdomjudge(pos >= 0 && pos < this->n);

    Nodo *actual = this->lista;
    for (int i = 0; i < pos; ++i)
    {
        actual = actual->siguienteNodo;
    }

    return actual;
}

int ListaEnlazada::getValor(int pos)
{
    assertdomjudge(pos >= 0 && pos < this->n); 

    Nodo *nodo = this->getNodo(pos);

    return nodo->elemento; 
}

void ListaEnlazada::setValor(int pos, int nuevoValor)
{
    assertdomjudge(pos >= 0 && pos < this->n);

    Nodo *nodo = this->getNodo(pos);
    nodo->elemento = nuevoValor;
}

int ListaEnlazada::getN()
{
    return this->n;
}

void ListaEnlazada::insertar(int pos, int nuevoValor)
{
    assertdomjudge(pos >= 0 && pos <= this->n);

    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->elemento = nuevoValor;
    nuevoNodo->siguienteNodo = nullptr;

    if (pos == 0)
    {
        nuevoNodo->siguienteNodo = this->lista;
        this->lista = nuevoNodo;
    }
    else
    {
        Nodo *anterior = this->getNodo(pos - 1);
        if (anterior != nullptr)
        {
            nuevoNodo->siguienteNodo = anterior->siguienteNodo;
            anterior->siguienteNodo = nuevoNodo;
        }
    }

    this->n++;
}

void ListaEnlazada::eliminar(int pos)
{
    assertdomjudge(pos >= 0 && pos < this->n);

    Nodo *eliminarNodo = nullptr;

    if (pos == 0)
    {
        eliminarNodo = this->lista;
        this->lista = this->lista->siguienteNodo;
    }
    else
    {
        Nodo *anterior = this->getNodo(pos - 1);
        if (anterior != nullptr)
        {
            eliminarNodo = anterior->siguienteNodo;
            anterior->siguienteNodo = eliminarNodo->siguienteNodo;
        }
    }

    delete eliminarNodo;
    this->n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
    assertdomjudge(listaAConcatenar != nullptr && listaAConcatenar->n > 0); 

    Nodo *actual = this->lista;
    if (actual == nullptr)
    {
        this->lista = listaAConcatenar->lista;
    }
    else
    {
        while (actual->siguienteNodo != nullptr)
        {
            actual = actual->siguienteNodo;
        }
        actual->siguienteNodo = listaAConcatenar->lista;
    }

    this->n += listaAConcatenar->n;
}

int ListaEnlazada::buscar(int elementoABuscar)
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->getValor(i) == elementoABuscar)
        {
            return i;
        }
    }

    return -1; 
}
