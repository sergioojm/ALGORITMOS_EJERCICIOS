#include <iostream>

#define NUM_FILAS 10
#define MAX_MOVIMIENTOS 4

using namespace std;

/*

Sergio Julbez Mendez | 2º INSO A

Big O = O(4^NUM_FILAS*NUM_FILAS) -> 4 combinaciones posibles por casilla
T(n) = 4*T(n*m) -1

M(n*m) -> O(1) espacial

*/


void printMatriz(char** arr)
{
      for (int i = 0; i < NUM_FILAS; i++)
      {
          for (int j = 0; j < NUM_FILAS; j++)
          {
              cout << arr[i][j];
          }
          cout << endl;
      }
}

/*
..********
*.*......*
*.*.****.*
*.*.*..*.*
*.*.*T.*.*
*.*.**.*.*
*.*....*.*
*.******.*
*........*
**********


..********
*.*......*
*.*.******
*.*.*..*.*
*.*.*T.*.*
*.*.**.*.*
*.*....*.*
*.******.*
*........*
**********

..********
*........*
*.********
*.*.*....*
*.*.*T.*.*
*.*.**.*.*
*.*....*.*
*.******.*
*........*
**********

*/

void probar(int *encontrado, int posX, int posY, char** tablero)
{
   

    int variacionX[MAX_MOVIMIENTOS] = {-1, 0, 1, 0};
    int variacionY[MAX_MOVIMIENTOS] = {0, 1, 0, -1};


    for (int posiblesMovimientos = 0; posiblesMovimientos < MAX_MOVIMIENTOS; posiblesMovimientos++)
    {
        int newPosX = posX + variacionX[posiblesMovimientos];
        int newPosY = posY + variacionY[posiblesMovimientos];

        //cout << newPosX << " ny" << newPosY << " varx" << variacionX[posiblesMovimientos] << " vary" << variacionY[posiblesMovimientos] << endl;

        // posicion correcta
        // y es una casilla valida
        if (   ((newPosX >= 0) && (newPosX < NUM_FILAS)) 
            && ((newPosY >= 0) && (newPosY < NUM_FILAS))
            && tablero[newPosX][newPosY] != '*' 
            && tablero[newPosX][newPosY] != 'X' 
            && !*encontrado
        )
        {
            if (tablero[newPosX][newPosY] == 'T') 
            {
                *encontrado = 1;
                printMatriz(tablero);
                cout << "ENCONTRADO " << newPosX << " " << newPosY;
                return; 
            } 
            

            if (tablero[newPosX][newPosY] == '.') 
            {
                tablero[newPosX][newPosY] = 'X'; 
                probar(encontrado, newPosX, newPosY, tablero);

                if (!*encontrado) tablero[newPosX][newPosY] = '.'; 
            }
        }
    }
    
}



int main(void)
{

    char** laberinto = new char*[NUM_FILAS];

    for (int i = 0; i < NUM_FILAS; i++)
    {
        laberinto[i] = new char[NUM_FILAS];
    }

    // generar matriz
    for (int i = 0; i < NUM_FILAS; i++)
    {
        for (int j = 0; j < NUM_FILAS; j++)
        {
            cin >> laberinto[i][j];
        }
    }

    laberinto[0][0] = 'X';

    int encontrado = 0;
    int inalcanzable = 1;

    probar(&encontrado, 0, 0, laberinto);

    if (!encontrado)
    {
        cout << "INALCANZABLE";
    }


    return 0;
}