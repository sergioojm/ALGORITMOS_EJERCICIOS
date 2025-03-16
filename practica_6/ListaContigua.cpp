#include "ListaContigua.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaContigua::ListaContigua(int incremento) 
{
    assertdomjudge(incremento > 0);

    this->n = 0;
    this->capacidad = incremento;
    this->incremento = incremento;
    this->vector = (int*)malloc(this->capacidad * sizeof(int));

    assertdomjudge(this->vector != nullptr);
}

ListaContigua::~ListaContigua() 
{
    free(this->vector);
}

int ListaContigua::getValor(int posicion) 
{
    assertdomjudge(posicion < this->n && posicion >= 0);
    return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor) 
{
    assertdomjudge(posicion < this->n && posicion >= 0);
    this->vector[posicion] = nuevoValor;
}

int ListaContigua::getN() 
{
    return this->n;
}

int ListaContigua::getCapacidad() 
{
    return this->capacidad;
}

void ListaContigua::insertar(int posicion, int nuevoValor) 
{
    assertdomjudge(posicion <= this->n && posicion >= 0);
    
    if (this->n == this->capacidad) 
    {
        this->capacidad += this->incremento;
        this->vector = (int*)realloc(this->vector, this->capacidad * sizeof(int));

        assertdomjudge(this->vector != nullptr);
    }

    memmove(this->vector + posicion + 1, this->vector + posicion, (this->n - posicion) * sizeof(int));
    this->vector[posicion] = nuevoValor;
    this->n++;
}

void ListaContigua::eliminar(int posicion) 
{
    assertdomjudge(posicion < this->n && posicion >= 0);
    
    memmove(this->vector + posicion, this->vector + posicion + 1, (this->n - posicion - 1) * sizeof(int));
    this->n--;

    if (this->n <= this->capacidad - 2 * this->incremento) 
    {
        this->capacidad -= this->incremento;
        this->vector = (int*)realloc(this->vector, this->capacidad * sizeof(int));

        assertdomjudge(this->vector != nullptr);
    }
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar) 
{
    assertdomjudge(listaAConcatenar != nullptr);
    
    int numeroDeIncrementos = this->n + listaAConcatenar->n;
    numeroDeIncrementos = numeroDeIncrementos / this->incremento;
   
    
    if (this->capacidad < numeroDeIncrementos * this->incremento) 
    {
        this->capacidad = numeroDeIncrementos * this->incremento;
        this->vector = (int*)realloc(this->vector, this->capacidad * sizeof(int));
        assertdomjudge(this->vector != nullptr);
    }

    memmove(this->vector + this->n, listaAConcatenar->vector, listaAConcatenar->n * sizeof(int));
    this->n += listaAConcatenar->n;
}


int ListaContigua::buscar(int elementoABuscar) 
{

    int res = -1;

    for (int i = 0; i < this->n; i++) 
    {
        if (this->vector[i] == elementoABuscar) 
        {
            res = i;
        }
    }
    
    return res;
}
