#include "Cola.h"
#include<iostream>

using namespace std;


Cola::Cola()
{
    this->principio = nullptr;
    this->final = nullptr;
}

bool Cola::estaVacia()
{
    return this->principio == nullptr && this->final == nullptr;
}

void Cola::encolar(int num)
{

    Nodo *newNode = new Nodo(num, nullptr);


    if (this->estaVacia())
    {
        this->final = newNode;
        this->principio = newNode;
    }
    else
    {
        this->final->siguiente = newNode;
        this->final = newNode;
    }

    //cout << "Inserted " << num << endl;

   
}

int Cola::desencolar()
{

    int valor = -1;

    if (!this->estaVacia())
    {
        valor = this->principio->valor;

        Nodo *currentPrincipio = this->principio;
        this->principio = this->principio->siguiente;

        if (this->principio == nullptr) this->final = nullptr;

        delete currentPrincipio;
    }

    return valor;
}
