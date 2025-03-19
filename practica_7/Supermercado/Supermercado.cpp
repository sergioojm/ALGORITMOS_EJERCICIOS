#include "Supermercado.h"
#include<iostream>

using namespace std;


Supermercado::Supermercado(int n)
{
    this->n_cajas = n;
    this->cajas = (Cola*) malloc(sizeof(Cola) * n);
}

void Supermercado::nuevoUsuario(int n, int id)
{
    if (!this->cajaVacia(n))
    {
        this->cajas[n].encolar(id);
    }
}

void Supermercado::cerrarCaja(int n)
{
    if (!this->cajaVacia(n))
    {

        int continuar = -2;
        int cajasVisitada = 0;

        while(continuar = this->cajas[n].desencolar() != -1)
        {
            if (!this->cajaVacia(cajasVisitada) && continuar != -2 && continuar != -1)
            {
                this->cajas[cajasVisitada].encolar(continuar);
            }
            cajasVisitada++;

            if (cajasVisitada >= this->n_cajas) cajasVisitada = 0;
        }
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
        return false;
    }
}

