#include <iostream>

using namespace std;


int main(void)
{

	int salir = 0;
/*
	while(!salir)
	{
		int num = -1;
		int salto = -1;
		
		cin >> num >> salto;
		
		if (num == 0 && salto == 0)
		{
			salir = 1;
		}
		else
		{
			
			int *numeros = new int[num];
			
			for (int i = 0; i < num; i++)
			{
				numeros[i] = 0;
			}
			
			// buscar numeros que me salto
			for (int i = 0; i < num; i++)
			{
				if (i % salto == 0)
				{
					numeros[i] = 1;
				}
			}
			
			for (int i = 0; i < num; i++)
			{
				if (numeros[i] == 0)
				{
					cout << i << endl;
					break;
				}
			}			
		}
	
	}
*/
	int num = -1;
	int salto = -1;
	
	cin >> num >> salto;
	
	int *numeros = new int[num];
			
	for (int i = 0; i < num; i++)
	{
		numeros[i] = (i + 1);
	}
	
	int turboSalir = 0;
	int index = 0;
	int vueltas = 0;
	
	do
	{
		if (numeros[index] == -1) index++;
		
		if (vueltas == 1 && numeros[index] != -1)
		{
			cout << numeros[index];
			turboSalir = 1;
			break;
		}
		
		if (index % salto == 0)
		{
			numeros[index] = -1;
		}
		
		index++;
		
		if (index >= num)
		{
			index = 0;
			vueltas++;
		}
		
		if (vueltas >= 2) turboSalir = 1;
		
	} while(turboSalir == 0);


	return 0;	
}