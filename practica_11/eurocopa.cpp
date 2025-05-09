#include <iostream>

using namespace std;


/*
		si n < 2 return equipos;
		// casos base
		si n == 2 entonces
			
			si (ronda % 2 != 0)
			{
				return equipos[1]
			}
			else
			{
				return equipos[0]
			}
		end
	
		left pointer = equipos / 2
		right pointer = lenght - (equipos / 2)

		char winner = calcular_ganador(left, lenght/2, ronda + 1)
		char winner2 = calcular_ganador(right, lenght/2, ronda + 1)
		
		return calcular_ganador((winner U winner2), n, ronda); 
	*/


char calcular_ganador(char *equipos, int n, int ronda)
{
	if (n < 2) return equipos[0];
	
	if (n == 2)
	{
		if (ronda % 2 != 0)
		{
			cout << "Ronda " << ronda << " Ganador " << equipos[1] << endl;
			return equipos[1];
		}
		else
		{
			cout << "Ronda " << ronda << " Ganador " << equipos[0] << endl;
			return equipos[0];
		}
	}
	
	int halfLenght = n/2;
	char *left = new char[halfLenght];
	char *right = new char[halfLenght];
	
	for (int i = 0; i < halfLenght; i++) { left[i] = equipos[i]; }
	for (int j = halfLenght; j < n; j++) { right[j - halfLenght] = equipos[j]; }
	
	char winner1 = calcular_ganador(left,  n/2, ronda + 1);
	char winner2 = calcular_ganador(right, n/2, ronda + 1);
	
	//cout << "Ronda " << ronda+1 << " Ganador " << winner1 << endl;
	//cout << "Ronda " << ronda+1 << " Ganador " << winner2 << endl;
	
	char combination[2] = { winner1, winner2 };
	
	return calcular_ganador(combination, 2, ronda); 
}




int main()
{
	int n;
	cin >> n;
	char *equipos = new char[n+1];
	

	for(int i = 0;i <n; i++)
	{
		equipos[i]='A'+i;
	}
	
	equipos[n]=0;
	calcular_ganador(equipos,n,0);
}









