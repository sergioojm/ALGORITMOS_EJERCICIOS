#include "Supermercado.h"
#include<iostream>

using namespace std;


Supermercado::Supermercado(int n)
{
    this->n_cajas = n;
    this->cajas = (ColaPrioridad*) malloc(sizeof(ColaPrioridad) * n);
}

void Supermercado::nuevoUsuario(int n, int id)
{
    if (n >= 0 && n < this->n_cajas)
    {
        this->cajas[n].encolar(id);
    }
}

void Supermercado::cerrarCaja(int n)
{
    int i = 0;

    while(!this->cajaVacia(n) && i != this->n_cajas)
    {
        if(i != n && !cajaVacia(i))
        {
            this->nuevoUsuario(i, this->atenderUsuario(n));
        }
        
        i = (i + 1) % this->n_cajas;
    }
}



int Supermercado::atenderUsuario(int n)
{

    int userId = -1;

    if (!this->cajaVacia(n))
    {
        userId = this->cajas[n].desencolar();
    }

    return userId;
}

bool Supermercado::cajaVacia(int n)
{
    if (n >= 0 && n < this->n_cajas)
    {
        return this->cajas[n].estaVacia();
    }
    else
    {
        return true;
    }
}

