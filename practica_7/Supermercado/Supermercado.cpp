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
    int lastCajaVisited = -1;
    int salir = 0;

    do
    {
        userId = this->cajas[n].desencolar();
       
        if (userId != -1)
        {
            do
            {
                salir = 0;

                if (!this->cajaVacia(cajasVisitada) && cajasVisitada != n && lastCajaVisited < cajasVisitada)
                {
                    cout << "Encolado en caja " << cajasVisitada << " el numero " << userId << endl;
                    this->cajas[cajasVisitada].encolar(userId);
                    lastCajaVisited++;
                    salir = 1;
                }
    
                cajasVisitada++;
                if (cajasVisitada >= this->n_cajas) cajasVisitada = 0;
                if (lastCajaVisited >= this->n_cajas) lastCajaVisited = -1;

            } while(!salir);
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

