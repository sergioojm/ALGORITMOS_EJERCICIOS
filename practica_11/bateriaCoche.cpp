#include <iostream>

using namespace std;



int main(void)
{
	
	int numDeMovidas = 0;
	
	cin >> numDeMovidas;
	
	for (int br = 0; br < numDeMovidas; br++) // br br patapim
	{
		int numPilas = 1; // max 100k
		int minVoltage = 0; // max 1million
		
		cin >> numPilas >> minVoltage;
		
		int *coches = new int[numPilas];
		int *pilasUsadas = new int[numPilas];
		
		for(int i = 0; i <numPilas; i++)
		{
			cin >> coches[i];
			pilasUsadas[i] = 0;
		}
		
		int numCoches = 0;
		
		for (int i = 0; i < numPilas; i++)
		{
			//cout << coches[i] << " / " << endl;
			for (int j = 0; j < numPilas; j++)
			{
				
				if (coches[i] + coches[j] >= minVoltage && pilasUsadas[i] == 0 && pilasUsadas[j] == 0 && i != j) 
				{ 
					numCoches++; 
					pilasUsadas[j] = 1;
					pilasUsadas[i] = 1;
					//cout << coches[j] << " ";
				}
			}
			//cout << endl;
		}
		
		cout << numCoches << endl;
	}
	
	
	
	return 0;
}