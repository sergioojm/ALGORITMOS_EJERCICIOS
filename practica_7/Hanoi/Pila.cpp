#include"Pila.h"


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

  while(actual->siguiente != nullptr)
  {
    actual = actual->siguiente;
  }

  if (!actual->siguiente)
  {
    actual->siguiente = new Nodo(num, nullptr);
  }

  // actual->valor = num;
  // actual->siguiente = nullptr;

}
  
int Pila::desapilar()
{    

  cout << "Desapilando disco " << 0 << " del poste " << this->name << endl;

}

bool Pila::estaVacia()
{

}

