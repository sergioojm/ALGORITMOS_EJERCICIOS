#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

ABB::ABB()
{
  this->n = 0;
  this->raiz = nullptr;
}

ABB::~ABB()
{
 eliminar(this->raiz);
}


void ABB::insertar(int nuevoElemento)
{
  Nodo* nuevoNodo = new Nodo;

  nuevoNodo->contenido = nuevoElemento;
  nuevoNodo->padre = NULL;
  nuevoNodo->hijoDerecho = NULL;
  nuevoNodo->hijoIzquierdo = NULL;

  if (n == 0)
  {
    this->raiz = nuevoNodo;
  }
  else
  {
    Nodo* nodoPadre = buscarHueco(raiz, nuevoElemento);

    if (nuevoElemento <= nodoPadre->contenido) 
    {
      nodoPadre->hijoIzquierdo = nuevoNodo;
    }
    else 
    {
      nodoPadre->hijoDerecho = nuevoNodo;
    }

    nuevoNodo->padre = nodoPadre;
  }

  this->n++;
}

Nodo* ABB::buscar(int elementoABuscar)
{
  return buscarRecursivo(this->raiz, elementoABuscar);
}

void ABB::eliminar(int elementoAEliminar)
{
  Nodo* nodoAEliminar = buscar(elementoAEliminar);

  eliminarNodo(nodoAEliminar);

  this->n--;

  if (n == 0) this->raiz = NULL;
}


void ABB::imprimir()
{
  if(this->raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(this->raiz);    
}

bool ABB::esABB()
{
  return esSubABB(this->raiz);
}

bool ABB::esAVL()
{
  return esABB() && esSubAVL(this->raiz);
}

void ABB::leerArbol()
{
  this->raiz=leerSubarbol(NULL);
}

/*
--------------------------------------------

    CLASES PROTECTED

--------------------------------------------
*/

void ABB::eliminarSubarbol(Nodo *raizSubarbol)
{
  assertdomjudge(raizSubarbol != nullptr);

  if (raizSubarbol->hijoIzquierdo != nullptr) eliminarSubarbol(raizSubarbol->hijoIzquierdo);
  if (raizSubarbol->hijoDerecho   != nullptr) eliminarSubarbol(raizSubarbol->hijoDerecho);

  if (raizSubarbol->padre != nullptr)
  {
    if (raizSubarbol->padre->hijoIzquierdo == raizSubarbol) raizSubarbol->padre->hijoIzquierdo = nullptr;
    if (raizSubarbol->padre->hijoDerecho   == raizSubarbol) raizSubarbol->padre->hijoDerecho   = nullptr;
  }

  delete raizSubarbol;
}


Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar)
{
  if (raizSubarbol == nullptr) return nullptr;

  if (elementoAInsertar <= raizSubarbol->contenido)
  {
    if (raizSubarbol->hijoIzquierdo == nullptr) return raizSubarbol;
    return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
  }
  else
  {
    if (raizSubarbol->hijoDerecho == nullptr) return raizSubarbol;
    return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
  }
}

Nodo* ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar)
{
  Nodo* nodoEncontrado = new Nodo();

  if(raizSubarbol == NULL)
  {
    return NULL;
  }
  else if(elementoABuscar == raizSubarbol->contenido)
  {
    return raizSubarbol;  
  }
  else if(elementoABuscar < raizSubarbol->contenido)
  {
    raizSubarbol = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
  } 
  else if(elementoABuscar > raizSubarbol->contenido)
  {
    raizSubarbol = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);

  }
    
  return raizSubarbol;
}

Nodo* ABB::buscarMaximo (Nodo *raizSubarbol)
{
  assertdomjudge(raizSubarbol != NULL);

  Nodo* max = nullptr;

  if (raizSubarbol->hijoDerecho == NULL)
  {
    max =  raizSubarbol;
  }
  else
  { 
    max = buscarMaximo(raizSubarbol->hijoDerecho);
  }
  
  return max;

}

Nodo* ABB::buscarMinimo (Nodo *raizSubarbol)
{
  assertdomjudge(raizSubarbol != NULL);

  Nodo* min = nullptr;

  if (raizSubarbol->hijoIzquierdo == NULL)
  {
    min =  raizSubarbol;
  }
  else
  { 
    min = buscarMaximo(raizSubarbol->hijoIzquierdo);
  }
  
  return min;
}

void ABB::eliminarNodo (Nodo *nodoParaEliminar)
{
  assertdomjudge(nodoParaEliminar != NULL);

  Nodo* nodoABorrar = new Nodo();

  if(nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo == NULL) 
  {

    if(nodoParaEliminar == this->raiz)
    {
      raiz = NULL;
    }
    else if(nodoParaEliminar == nodoParaEliminar->padre->hijoDerecho)
    {
      nodoParaEliminar->padre->hijoDerecho = NULL;
    }
    else
    {
      nodoParaEliminar->padre->hijoIzquierdo = NULL;
    }

    delete nodoParaEliminar;

  }
  else 
  {
    if(nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL)
    {
      nodoABorrar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
      nodoParaEliminar->contenido = nodoABorrar->contenido;
      eliminarNodo(nodoABorrar);
    }
    else if(nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo == NULL)
    { 
      nodoABorrar = buscarMinimo(nodoParaEliminar->hijoDerecho);
      nodoParaEliminar->contenido = nodoABorrar->contenido;
      eliminarNodo(nodoABorrar);
    }
    else if(nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL)
    { 
      if(alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo))
      { 
        nodoABorrar = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = nodoABorrar->contenido;
        eliminarNodo(nodoABorrar);
      }
      else
      {
        nodoABorrar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = nodoABorrar->contenido;
        eliminarNodo(nodoABorrar);
      }
    }
  }
}

int ABB::alturaNodo(Nodo *raizSubarbol)
{
  if (raizSubarbol == nullptr) return -1;

  int altIzq = alturaNodo(raizSubarbol->hijoIzquierdo);
  int altDrh = alturaNodo(raizSubarbol->hijoDerecho);

  if (altIzq > altDrh) 
  {
    return altIzq + 1;
  }
  else 
  {
    return altDrh + 1;
  }


}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

bool  ABB::esSubABB(Nodo *raizSubarbol)
{
  if(raizSubarbol == NULL)
  {
    return true;
  }
  else
  {
    bool esABBIzquierda = true;
    bool esABBDerecha   = true;
  
    if(raizSubarbol->hijoIzquierdo != NULL)
    {
      esABBIzquierda = (buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);
    }
      

    if (raizSubarbol->hijoDerecho != NULL)
    {
      esABBDerecha = (buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoDerecho);
    }
     
    
    return (esABBIzquierda && esABBDerecha);
  }
}


bool ABB::esSubAVL(Nodo *raizSubarbol)
{
  if (raizSubarbol == NULL)
  {
    return true;
  }

  int diferenciaAlturas = alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho);

  if (diferenciaAlturas > 1 || diferenciaAlturas < -1) return false;


  return esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho);
}


Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


