#include <iostream>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

using namespace std;

/*

O(n^2) temporal
O(n*m) espacial (reservar la matriz)

*/

void createPascalTriangle(int** triangle)
{

    for (int i = 0; i < MAX_FILAS; i++)
    {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 0; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

int main(void)
{
    int n, r;

    int** trianguloPascal = new int*[MAX_FILAS];

    for (int i = 0; i < MAX_FILAS; i++)
    {
        trianguloPascal[i] = new int[MAX_COLUMNAS];
    }

    createPascalTriangle(trianguloPascal);

    // for (int i = 0; i < MAX_FILAS; i++)
    // {
    //     for (int j = 0; j < MAX_COLUMNAS; j++)
    //     {
    //         cout << trianguloPascal[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(true)
    {
        cin >> n >> r;
    
        if (n < 0 || r < 0) break;
        
    
        if (r > n) {
            cout << "ERROR" << endl;
            continue;
        }
    
        cout << trianguloPascal[n][r] << endl;
    }

  

    return 0;
}