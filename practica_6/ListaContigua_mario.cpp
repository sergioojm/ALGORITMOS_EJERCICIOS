#include "ListaContigua.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaContigua::ListaContigua(int incremento){
    assertdomjudge(incremento>0);
    ListaContigua::n = 0;
    ListaContigua::capacidad=incremento;
    ListaContigua::incremento=incremento;
    ListaContigua::vector=(int*)malloc(capacidad * sizeof(int));
}
ListaContigua::~ListaContigua(){
    free(vector);
}

int ListaContigua::getValor(int posicion){
    assertdomjudge(posicion<n && posicion>=0);
    return *(vector + posicion);
}

void ListaContigua::setValor(int posicion, int nuevoValor){
    assertdomjudge(posicion<n && posicion>=0);
    *(vector + posicion) = nuevoValor;
}

int ListaContigua::getN(){
    return n;
}

int ListaContigua::getCapacidad(){
    return capacidad;
}

void ListaContigua::insertar(int posicion, int nuevoValor){
    assertdomjudge(posicion<=n && posicion>=0);
    if (n==capacidad){
        capacidad+=incremento;
        vector = (int*)realloc(vector, capacidad * sizeof(int));
        for (int i = n+1; i<capacidad; i++) *(vector+i)=0;
    }

    memmove(vector+posicion+1, vector+posicion, (n-posicion) * sizeof(int));
    *(vector+posicion) = nuevoValor;
    n++;
}

void ListaContigua::eliminar(int posicion){
    assertdomjudge(posicion<n && posicion>=0);
    memmove(vector+posicion, vector+posicion+1, (n-posicion-1) * sizeof(int));
    n--;
    if (n<=capacidad-2*incremento){
        capacidad-=incremento;
        vector = (int*)realloc(vector, capacidad * sizeof(int));
        for (int i = n+1; i<capacidad; i++) *(vector+i)=0;
    }
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar){
    assertdomjudge(n>0);
    float espacio = n + listaAConcatenar->n;
    espacio = espacio/incremento;
    espacio = ceil(espacio);
    if (capacidad < espacio*incremento){
        capacidad=espacio*incremento;
        vector = (int*)realloc(vector, capacidad * sizeof(int));
    }
    memmove(vector+n, listaAConcatenar->vector, (listaAConcatenar->n) * sizeof(int));
    n=n+listaAConcatenar->n;
    for (int i = n+1; i<capacidad; i++) *(vector+i)=0;
}

int ListaContigua::buscar(int elementoABuscar){
    for (int i = 0; i < n; i++)
    if(*(vector + i) == elementoABuscar) return i;
    
    return -1;
}