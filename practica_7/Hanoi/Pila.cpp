#include"Pila.h"


Pila::Pila(string name)
{
  this->name = name;
}

std::string Pila::nombrePila()
{
  return this->name;
}

void Pila::apilar(int num)
{
  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}
  
int Pila::desapilar()
{    

  cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;

}

bool Pila::estaVacia()
{

}

