#include "ListaEnlazada.h"
#include "Nodo.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void DestroyNodes(Nodo *node, int pos, int n){
    if (++pos < n) DestroyNodes(node->siguienteNodo, pos, n);
    delete node;
}

ListaEnlazada::ListaEnlazada(){
	n=0;
    lista = nullptr;
}
ListaEnlazada::~ListaEnlazada(){
    DestroyNodes(lista, 0, n);
}

Nodo* ListaEnlazada::getNodo (int posicion){
    assertdomjudge(posicion>=0 && posicion<n);
    Nodo *nodo = lista;
    for (int i=0; i<posicion; i++){
        nodo=nodo->siguienteNodo;
    }
    return nodo;
}

int ListaEnlazada::getValor(int posicion){
    assertdomjudge(posicion>=0 && posicion<n);
    Nodo *nodo = getNodo(posicion);
    return nodo->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor){
    assertdomjudge(posicion>=0 && posicion<n);
    Nodo *nodo = getNodo(posicion);
    nodo->elemento = nuevoValor;
}

int ListaEnlazada::getN(){
    return n;
}

void ListaEnlazada::insertar (int posicion, int nuevoValor){
    assertdomjudge(posicion>=0 && posicion<=n);

    Nodo *lastNode = nullptr;
    if (posicion > 0){
        lastNode = getNodo(posicion-1);
    }
    Nodo *newNode=new Nodo;
    Nodo *nextNode=nullptr;
    if (lastNode==nullptr) { nextNode = lista; lista=newNode; }     // 0
    else{
        if (lastNode->siguienteNodo == nullptr) nextNode = nullptr; // n
        else nextNode = lastNode->siguienteNodo;                    // 1..n-1
        lastNode->siguienteNodo = newNode;
    }

    newNode->siguienteNodo = nextNode;
    newNode->elemento = nuevoValor;
    n++;
}

void ListaEnlazada::eliminar (int posicion){
    assertdomjudge(posicion>=0 && posicion<n);

    Nodo *lastNode = nullptr;
    if (posicion > 0){
        lastNode = getNodo(posicion-1);
    }

    Nodo *nextNode = nullptr;
    if (lastNode==nullptr){
        nextNode = lista->siguienteNodo;
        delete lista;
        lista = nextNode;
    }
    else{
        nextNode = lastNode->siguienteNodo->siguienteNodo;
        delete lastNode->siguienteNodo;
        lastNode->siguienteNodo = nextNode;
    }
    n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
    assertdomjudge(listaAConcatenar->n>0);
    for (int i = 0; i < listaAConcatenar->n; i++)
    insertar(n, listaAConcatenar->getValor(i));
}

int ListaEnlazada::buscar(int elementoABuscar){
    for (int i = 0; i < n; i++)
    if (getValor(i) == elementoABuscar) return i;

    return -1;
}