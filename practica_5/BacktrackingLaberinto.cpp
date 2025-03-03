#include <iostream>

#define NUM_FILAS 10
#define MAX_MOVIMIENTOS 4

using namespace std;

void printMatriz(char** arr)
{
      for (int i = 0; i < NUM_FILAS; i++)
      {
          for (int j = 0; j < NUM_FILAS; j++)
          {
              cout << arr[i][j] << " ";
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

*/

void probar(int *encontrado, int posX, int posY, char** tablero)
{
    int posiblesMovimientos = -1;

    do
    {
        posiblesMovimientos++;
        
        int variacionX[MAX_MOVIMIENTOS] = {-1, 0, 1, 0};
        int variacionY[MAX_MOVIMIENTOS] = {0, 1, 0, -1};
  
        int newPosX = posX + variacionX[posiblesMovimientos];
        int newPosY = posY + variacionY[posiblesMovimientos];

        //cout << newPosX << " ny" << newPosY << " varx" << variacionX[posiblesMovimientos] << " vary" << variacionY[posiblesMovimientos] << endl;

        if (posiblesMovimientos == MAX_MOVIMIENTOS - 1 && !*encontrado)
        {
            cout << "INALCANZABLE";
            break;
        }
        // posicion correcta
        // y es una casilla valida
        if ((newPosX >= 0) && (newPosX < NUM_FILAS) && (newPosY >= 0) && (newPosY < NUM_FILAS) 
            && tablero[newPosX][newPosY] != '*' && !*encontrado
        )
        {
            
            if (tablero[newPosX][newPosY] == 'T')
            {
                *encontrado = true;
                printMatriz(tablero);
                cout << "ENCONTRADO " << newPosX << " " << newPosY;
            }
            else if (tablero[newPosX][newPosY] == '.')
            {
                tablero[newPosX][newPosY] = 'X';
                probar(encontrado, newPosX, newPosY, tablero);
            }
        }

    } while (!*encontrado || posiblesMovimientos < MAX_MOVIMIENTOS);
    


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

    probar(&encontrado, 0, 0, laberinto);

    // for (int i = 0; i < NUM_FILAS; i++)
    // {
    //     for (int j = 0; j < NUM_FILAS; j++)
    //     {
    //         cout << laberinto[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}