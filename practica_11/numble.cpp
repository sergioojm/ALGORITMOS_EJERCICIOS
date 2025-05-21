#include <iostream>

using namespace std;

void print(int *nums)
{	
	for (int i = 0; i < 4; i++)
	{
		cout << nums[i];
	}
	cout << endl;
}

int comprobar(int num, int *nums)
{
	int suma = 0;
	
	for (int i = 0; i < 4; i++)
	{
		suma += nums[i];
		if (nums[i] == -1) suma = 0;
	}
	
	return suma == num;
}

/*

	pruebo

	miro mis 4 numeros

	si alguno de mis numeros es -1, tengo q probar combinaciones

			pruebo las 10 combinaciones que tengo posibles del 0 al 9
				si alguna da que la suma es mi numero, entonces exito = 1

*/

void probar(int *numeros, int numSumar, int pos)
{
	if (pos >= 5) return;

	if (comprobar(numSumar, numeros))
	{
		print(numeros);
		return;
	}
	
	if (numeros[pos] == -1)
	{
		// 10 es el num de movimientos
		for (int j = 0; j < 10; j++)
		{
			numeros[pos] = j;
			probar(numeros, numSumar, pos + 1);
		}
		numeros[pos] = -1; // mantener las demas llamadas recursivas
	}
	else
	{
		probar(numeros, numSumar, pos + 1);
	}
}


int main(void)
{
	int *numeros = new int[4];
	int numSumar = 0;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> numeros[i];
	}
	
	cin >> numSumar;
	
	probar(numeros, numSumar, 0);
	
	return 0;
}