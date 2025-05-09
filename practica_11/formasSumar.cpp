#include <iostream>

using namespace std;

int comprobar(int num, int *nums)
{
	int contador = 0;
	
	for (int i = 0; i < num; i++)
	{
		contador += nums[i];
	}
	
	return contador == num;
}

void print(int num, int *nums)
{	
	for (int i = 0; i < num; i++)
	{
		cout << nums[i];
	}
	cout << endl;
}

int main()
{
	
	int num = 1;
	cin >> num;
	
	int contador = 1;
	
	int *numeros = new int[num];
	
	for (int i = 0; i < num; i++) { numeros[i] = 1; }
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (comprobar(num, numeros))
			{
				print(num, numeros);
			}
			numeros[j] = contador;
		}
		contador++;
	}

	
	return 0;
}



/*

	3 -> [1, 2]
	
	[1, 1, 1]

	func probar(num, total)
	{
		si Sum(num) hasta total == total return true;
	}
		

*/