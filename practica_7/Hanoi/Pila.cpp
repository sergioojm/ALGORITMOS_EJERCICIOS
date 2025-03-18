#include"Pila.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

Pila::Pila(string name)
{
  this->name = name;
  this->cima = nullptr;
}

std::string Pila::nombrePila()
{
  return this->name;
}

void Pila::apilar(int num)
{
  cout << "Apilando disco " << num <<" en poste " << this->name <<endl;

  if (this->cima == nullptr)
  {
    this->cima = new Nodo(num);
    this->cima->siguiente = nullptr;
  }
 
  Nodo *actual = this->cima;
  Nodo *newCima = new Nodo(num, actual);
  this->cima = newCima;

  if (this->cima == nullptr)
  {
    cout << "cima es null" << endl;
  }

  
  // Nodo *palWhile = this->cima;
  // while( palWhile->siguiente != nullptr )
  // {
  //   cout << "Nodo con valor " << palWhile->valor << endl;
  //   palWhile = palWhile->siguiente;
  // }

}
  
int Pila::desapilar()
{    
  assertdomjudge(this->cima != nullptr);

  int valor = this->cima->valor;

  cout << "Desapilando disco " << valor << " del poste " << this->name << endl;

  Nodo *actual = this->cima;
  this->cima = actual->siguiente;

  free(actual);

  return valor;
}

bool Pila::estaVacia()
{
  return this->cima == nullptr;
}

