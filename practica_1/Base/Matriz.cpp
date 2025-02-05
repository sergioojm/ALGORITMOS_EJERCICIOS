#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}


/*

    --------------  Constructores  ---------------

    y deconstructor
*/

Matriz::~Matriz()
{
  for (int i = 0; i < this->n_filas; i++)
  {
    delete[] this->matriz[i];
  }

  delete[] this->matriz;
}

Matriz::Matriz ()
{
  this->matriz = NULL;
  this->n_columnas = 0;
  this->n_filas = 0;
}

Matriz::Matriz(const int numFilas, const int numColumnas)
{
  this->n_columnas = numColumnas;
  this->n_filas = numFilas;

  this->matriz = (double **) new double *[numFilas];

  for (int i = 0; i < numFilas; i++)
  {
    this->matriz[i] = new double [numColumnas];
  }

}

Matriz::Matriz(const Matriz &m)
{
  // crear la matriz
  this->n_columnas = m.n_columnas;
  this->n_filas = m.n_filas;

  this->matriz = (double **) new double *[m.n_filas];

  for (int i = 0; i < m.n_filas; i++)
  {
    this->matriz[i] = new double [m.n_columnas];
  }

  // copiar matrix

  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      this->matriz[i][j] = m.matriz[i][j];
    }
  }

}

// Asignacion de matrices

Matriz &Matriz::operator=(const Matriz &m)
{
  if (matriz != NULL)
  {
    for (int i = 0; i < n_filas; i++)
      delete[] matriz[i];

    delete[] matriz;
    matriz = NULL;
  }

  this->n_filas = m.n_filas;
  this->n_columnas = m.n_columnas;
  this->matriz = NULL;
  if (n_filas > 0 && n_columnas > 0)
  {
    matriz = new double *[n_filas];

    for (int i = 0; i < n_filas; i++)
    {
      matriz[i] = new double[n_columnas];
      for (int j = 0; j < n_columnas; j++)
        matriz[i][j] = m.matriz[i][j];
    }
  }

  return (*this);
}

Matriz &Matriz::operator+ (const Matriz &m)
{

  assertdomjudge(this->n_columnas == m.n_columnas && this->n_filas == m.n_filas);

  Matriz *resultMatrix = new Matriz(this->n_filas, this->n_columnas);

  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      resultMatrix->matriz[i][j] = this->matriz[i][j] + m.matriz[i][j];
    }
  }

  return (*resultMatrix);
}

Matriz &Matriz::operator- (const Matriz &m)
{

  assertdomjudge(this->n_columnas == m.n_columnas && this->n_filas == m.n_filas);

  Matriz *resultMatrix = new Matriz(this->n_filas, this->n_columnas);

  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      resultMatrix->matriz[i][j] = this->matriz[i][j] - m.matriz[i][j];
    }
  }

  return (*resultMatrix);
}

Matriz &Matriz::operator* (const double escalar)
{
  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      this->matriz[i][j] *= escalar;
    }
  }

  return (*this);
}

Matriz &Matriz::operator* (const Matriz &m)
{
  //assertdomjudge(this->n_columnas == m.n_filas);
  Matriz *resultMatrix = NULL;

  if (this->n_columnas != m.n_filas)
  {
    return (*resultMatrix);
  }

  resultMatrix = new Matriz(this->n_filas, m.n_columnas);

  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < m.n_columnas; j++)
    {
      for (int k = 0 ; k < this->n_filas; k++)
      {
        resultMatrix->matriz[i][j] += this->matriz[i][k] * m.matriz[k][j];
      }
    }
  }

  return (*resultMatrix);
}

// es simetrica
bool Matriz::esSimetrica()
{
  bool result = true;

  //assertdomjudge(this->n_filas != this->n_columnas);

  if (this->n_filas != this->n_columnas)
  {
    return false;
  }


  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      if (this->matriz[i][j] != this->matriz[j][i])
      {
        result = false;
      }
    }
  }

  return result;
}

	double Matriz::obtenerMaximo()
  {

    double result = this->matriz[0][0];

    for (int i = 0; i < this->n_filas; i++)
    {
      for (int j = 0; j < this->n_columnas; j++)
      {
        if (this->matriz[i][j] > result)
        {
          result = this->matriz[i][j];
        }
      }
    }

    return result;
  }


	double Matriz::obtenerMinimo()
  {
    double result = this->matriz[0][0];

    for (int i = 0; i < this->n_filas; i++)
    {
      for (int j = 0; j < this->n_columnas; j++)
      {
        if (this->matriz[i][j] < result)
        {
          result = this->matriz[i][j];
        }
      }
    }

    return result;
  }

Matriz Matriz::calcularTraspuesta()
{

  Matriz *transposedMatrix = new Matriz(this->n_columnas, this->n_filas);

  for (int i = 0; i < this->n_filas; i++)
  {
    for (int j = 0; j < this->n_columnas; j++)
    {
      transposedMatrix->matriz[j][i] = this->matriz[i][j];
    }
  }


  return (*transposedMatrix);
}

// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
  {
    cout << "Fila " << i << endl;
    for (int j = 0; j < n_columnas; j++)
    {
      cout << "Elemento " << j << endl;
      cin >> elemento;
      matriz[i][j] = elemento;
    }
    cout << endl;
  }
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j] = rand();
}

// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
  {
    for (int j = 0; j < n_columnas; j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }
}
