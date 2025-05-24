#include <iostream>
#include "pais.h"

#define COUNTRY_SIZE 4

using namespace std;

Pais get_ganador(Pais *paises, int num_paises)
{

  if (num_paises == 2)
  {
  
    if (paises[0].puntuacion > paises[1].puntuacion)
    {
      paises[0].puntuacion += paises[1].puntuacion;
      cout << "Ha ganado " << paises[0].pais << " con " << paises[0].puntuacion << endl; 
      return paises[0];
    }
    else
    {
      paises[1].puntuacion += paises[0].puntuacion;
      cout << "Ha ganado " << paises[1].pais << " con " << paises[1].puntuacion << endl;
      return paises[1];
    }

  }

  int half = num_paises/2;
  Pais* left = new Pais[half];
  Pais* right = new Pais[half];

  for (int i = 0; i < half; i++) left[i] = paises[i];
  for (int i = half; i < num_paises; i++) right[i - half] = paises[i];

  Pais winner1 = get_ganador(left, half);
  Pais winner2 = get_ganador(right, half);

  Pais *combination = new Pais[2];
  combination[0] = winner1;
  combination[1] = winner2;

  return get_ganador(combination, 2);
}

int main()
{
  
  Pais *pais = new Pais[COUNTRY_SIZE];

  pais[0].pais = "ES";
  pais[0].puntuacion = 5;

  pais[1].pais = "DE";
  pais[1].puntuacion = 4;

  pais[2].pais = "IT";
  pais[2].puntuacion = 1;

  pais[3].pais = "FR";
  pais[3].puntuacion = 7;

  get_ganador(pais, COUNTRY_SIZE);

  return 0;
}
