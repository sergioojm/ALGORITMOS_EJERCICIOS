#include <iostream>

using namespace std;

void print(int num, int *nums)
{	
	for (int i = 0; i < num; i++)
	{
		cout << nums[i];
	}
	cout << endl;
}

int comprobar(int num, int *nums)
{
	int contador = 0;
	
	for (int i = 0; i < num; i++)
	{
		contador += nums[i];
	}
	
	return contador == num;
}

void probar(int *numeros, int* exito, int numSumar)
{
	for (int i = 0; i < 4; i++)
	{
		if (numeros[i] == -1)
		{
			// 10 es el num de movimientos
			for (int i = 0; i < 10; i++)
			{
				numeros[i] = i;
				probar(numeros, exito, numSumar);
				
				if (comprobar(numSumar, numeros))
				{
					*(exito) = 1;
				}
				else
				{
					
					
					if (exito[0] != 1)
					{
						numeros[i] = -1;
					}
				}
				
				
				if (exito[0] == 1)
				{
					print(numSumar, numeros);
				}
			}
		}
	}
}



/*

busco en mis numeros

si alguno es -1, probar los 10 numeros




*/

int main(void)
{
	int *numeros = new int[4];
	int numSumar = 0;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> numeros[i];
	}
	
	cin >> numSumar;
	
	probar(numeros, 0, numSumar);
	
	return 0;
}