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
    if (n >= 0 && n < this->n_cajas)
    {
        this->cajas[n].encolar(id);
    }
}

void Supermercado::cerrarCaja(int n)
{
    int continuar = -2;
    int cajasVisitada = 0;

    // cambiar a do while
    while(continuar = this->cajas[n].desencolar() != -1)
    {
        cout << continuar;
        if (!this->cajaVacia(cajasVisitada) && continuar != -2 && continuar != -1)
        {
            cout << "Encolado en caja " << cajasVisitada << " el numero " << continuar;
            this->cajas[cajasVisitada].encolar(continuar);
        }
        cajasVisitada++;

        if (cajasVisitada >= this->n_cajas) cajasVisitada = 0;
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

