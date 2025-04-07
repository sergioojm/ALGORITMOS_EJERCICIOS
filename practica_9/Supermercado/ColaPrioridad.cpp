#include "ColaPrioridad.h"
#include <iostream>
#include "assertdomjudge.h"

using namespace std;

ColaPrioridad::ColaPrioridad()
{
    this->vector = ListaContigua();
}

bool ColaPrioridad::estaVacia()
{
    return this->vector.getN() <= 0;
}

void ColaPrioridad::encolar(int nuevoElemento)
{

    this->vector.insertarAlFinal(nuevoElemento);

    int pos = this->vector.getN() - 1;
    int elPapa = (pos) / 2; 


    while (pos > 0 && this->vector.getValor(pos) < this->vector.getValor(elPapa))
    {
        int valorActual = this->vector.getValor(pos);
        int valorPadre  = this->vector.getValor(elPapa);

        this->vector.setValor(pos, valorPadre);
        this->vector.setValor(elPapa, valorActual);

        pos = elPapa;
        elPapa = (pos) / 2;
    }


}

int ColaPrioridad::desencolar()
{

    assertdomjudge(!this->estaVacia());


    int primerValor = this->vector.getValor(0);
    int lastValor = this->vector.getValor(this->vector.getN() - 1);
  
    this->vector.setValor(0, lastValor);
    this->vector.eliminarAlFinal();

    reestructurar();


    return primerValor;
}

void ColaPrioridad::reestructurar()
{
    if (this->vector.getN() <= 1) return;

    int size  = this->vector.getN();
    int firstRoot = 0;
    int salir = 0;


    while (!salir)
    {
        int hijoPos = (2 * firstRoot) + 1;
        int newRoot = firstRoot;

        if (hijoPos + 1 < size   && this->vector.getValor(newRoot) > this->vector.getValor(hijoPos + 1)) newRoot = hijoPos + 1;
        if (hijoPos < size       && this->vector.getValor(newRoot) > this->vector.getValor(hijoPos))     newRoot = hijoPos;

        if (firstRoot == newRoot)
        {
            salir = 1;
        }
        else
        {
            int temp = this->vector.getValor(newRoot);
            this->vector.setValor(newRoot, this->vector.getValor(firstRoot));
            this->vector.setValor(firstRoot, temp);
    
            firstRoot = newRoot;
        }
    }

}

