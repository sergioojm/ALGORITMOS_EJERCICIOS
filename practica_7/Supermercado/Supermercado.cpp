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
    int userId = -1;
    int cajasVisitada = 0;

    do
    {
        userId = this->cajas[n].desencolar();
       
        if (userId != -1)
        {
            int salir = 0;

            while (cajasVisitada < this->n_cajas && !salir)
            {
                if (!this->cajaVacia(cajasVisitada) && cajasVisitada != n)
                {
                    //cout << "Encolado en caja " << cajasVisitada << " el numero " << userId << endl;
                    this->cajas[cajasVisitada].encolar(userId);
                    salir = 1;
                }

                cajasVisitada++;
                if (cajasVisitada >= this->n_cajas) cajasVisitada = 0;
            }
        }

    } while (userId != -1);
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

