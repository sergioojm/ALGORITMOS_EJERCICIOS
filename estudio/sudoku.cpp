#include <iostream>

using namespace std;

#define MAX_TAM 9

int testSudoku(int **sudoku, int testRow, int testCol)
{
  // test row & col
  for (int i = 0; i < MAX_TAM; i++)
  {
    for (int j = 0; j < MAX_TAM; j++)
    {
      // test de la fila
      if (sudoku[testRow][i] == sudoku[testRow][j]) return 0;
      // si no hay valor igual en la fila, tenemos que comprobar su columna

      for (int ic = 0; i < MAX_TAM; ic++)
      {
        for (int jc = 0; j < MAX_TAM; jc++)
        {
          if (sudoku[ic][testCol] == sudoku[jc][testCol]) return 0;
        }
      }
    }
  }

  // test 3x3 box

  int boxRow = testRow - (testRow % 3);
  int boxCol = testCol - (testCol % 3);

  for (int i = boxRow; i < boxRow + 3; i++)
  {
    for (int j = boxCol; j < boxCol + 3; j++)
    {
      if (sudoku[i][j] == sudoku[testRow][testCol]) return 0;
    }
  }

  return 1;
}


void backtrackingSudoku(int **sudoku, int row)
{
 
}


int main(void)
{

    int sudoku[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int **sudokuPtr = new int*[MAX_TAM];
    for (int i = 0; i < MAX_TAM; i++)
    {
        sudokuPtr[i] = new int[MAX_TAM];
        for (int j = 0; j < MAX_TAM; j++)
        {
            sudokuPtr[i][j] = sudoku[i][j];
        }
    }

  backtrackingSudoku(sudokuPtr, 0);

  return 0;
}
