#include <iostream>

using namespace std;

#define MAX_TAM 9


void printSudoku(int sudoku[MAX_TAM][MAX_TAM])
{
  for (int i = 0; i < MAX_TAM; i++)
  {
    for (int j = 0; j < MAX_TAM; j++)
    {
      cout << sudoku[i][j] << " ";
    }
    cout << endl;
  }
}

int testSudoku(int sudoku[MAX_TAM][MAX_TAM], int testRow, int testCol)
{
  int valor = sudoku[testRow][testCol];

  if (valor == 0) return 0;

  // test row & col
  for (int i = 0; i < MAX_TAM; i++)
  {
    if (testCol != i && sudoku[testRow][i] == valor) return 0;
  }

  for (int i = 0; i < MAX_TAM; i++)
  {
    if (testRow != i && sudoku[i][testCol] == valor) return 0;
  }


  // test 3x3 box
  int boxRow = testRow - (testRow % 3);
  int boxCol = testCol - (testCol % 3);

  for (int i = boxRow; i < boxRow + 3; i++)
  {
    for (int j = boxCol; j < boxCol + 3; j++)
    {
      if (sudoku[i][j] == valor && (testRow != i || testCol != j)) return 0;
    }
  }

  return 1;
}

bool sudokuCompleted(int sudoku[MAX_TAM][MAX_TAM])
{

  for (int i = 0; i < MAX_TAM; i++)
  {
    for (int j = 0; j < MAX_TAM; j++)
    {
      if (sudoku[i][j] == 0 || testSudoku(sudoku, i, j) == 0) return false;
    }
  }

  return true;
}

void backtrackingSudoku(int sudoku[MAX_TAM][MAX_TAM], int row, int col, int *exito)
{

  if (exito[0]) return;

  if (row >= MAX_TAM) return;

  if (col >= MAX_TAM)
  {
    col = 0;
    backtrackingSudoku(sudoku, row+1, col, exito);
    return;
  }

  if (sudokuCompleted(sudoku))
  {
    printSudoku(sudoku);
    *exito = true;
    return;
  }

  if (sudoku[row][col] != 0)
  {
    backtrackingSudoku(sudoku, row, col + 1, exito); 
  }
  else
  {
    for (int i = 1; i <= MAX_TAM; i++)
    {
      sudoku[row][col] = i;
      if (testSudoku(sudoku, row, col))
      {
        backtrackingSudoku(sudoku, row, col + 1, exito);
      }
    }

    sudoku[row][col] = 0;
  }

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

  int exito = false;
  backtrackingSudoku(sudoku, 0, 0, &exito);

  return 0;
}
