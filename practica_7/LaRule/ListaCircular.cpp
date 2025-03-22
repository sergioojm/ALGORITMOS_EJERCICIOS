#include "ListaCircular.h"
#include <iostream>


using namespace std;


ListaCircular::ListaCircular()
{
    this->lista = nullptr;
    this->n = 0;
}

ListaCircular::~ListaCircular()
{
    Nodo *actual = this->lista;

    while (actual != nullptr)
    {
        Nodo *temp = actual;
        actual = actual->siguienteNodo;
        delete temp;
    }
}


Nodo* ListaCircular::getNodo(int posicion)
{
    Nodo *devolver = this->lista;

    if (devolver == nullptr) return nullptr;

    for (int i = 0; i < posicion; ++i)
    {
        devolver = devolver->siguienteNodo;
    }

    return devolver;
}

int ListaCircular::getN()
{
    return this->n;
}

string ListaCircular::getValor(int posicion)
{
    return  this->getNodo(posicion)->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor)
{
    this->getNodo(posicion)->elemento = nuevoValor;
}

void ListaCircular::insertar(int posicion, string nuevoValor)
{
    Nodo *newNodo = new Nodo();
    newNodo->elemento = nuevoValor;


    if (this->lista == nullptr)
    {
        this->lista = newNodo;
        this->lista->anteriorNodo = newNodo;
        this->lista->siguienteNodo = newNodo;
    }
    else
    {
        Nodo *anterior = this->getNodo(posicion - 1);

        newNodo->siguienteNodo = anterior->siguienteNodo;
        newNodo->anteriorNodo = anterior;

        anterior->siguienteNodo->anteriorNodo = newNodo;
        anterior->siguienteNodo = newNodo;

        if (posicion == 0) this->lista = newNodo;
    }

    this->n++;
}

void ListaCircular::eliminar(int posicion)
{

    Nodo *elNodo = this->getNodo(posicion);


    if (elNodo != nullptr)
    {   

        if (this->n == 1) 
        {
            this->lista = nullptr;
        }
        else
        {
            elNodo->anteriorNodo->siguienteNodo = elNodo->siguienteNodo;
            elNodo->siguienteNodo->anteriorNodo = elNodo->anteriorNodo;


            if (posicion == 0) this->lista = elNodo->siguienteNodo;
        }

      
        delete elNodo;
        this->n--;
    }
}

void ListaCircular::girar(int p)
{
    if (p > 0)
    {
        for (int i = 0; i < p; i++)
        {
            this->lista = this->lista->siguienteNodo;
        }
    }
    else if (p < 0)
    {
        for (int i = 0; i > p; i--)
        {
            this->lista = this->lista->anteriorNodo;
        }
    }
}