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
    while (actual->siguienteNodo != nullptr)
    {
        actual = actual-siguienteNodo;
        delete actual->anteriorNodo;
    }
}

Nodo* ListaCircular::getNodo(int posicion)
{
    Nodo *devolver = this->lista;

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

void setValor(int posicion, string nuevoValor)
{
    this->getNodo(posicion)->elemento = nuevoValor;
}