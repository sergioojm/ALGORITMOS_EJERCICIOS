#include <iostream>
#include <cmath>

using namespace std;

#define NUM_MONEDAS 8

/*

Sergio Julbez Mendez | 2º INSO A

Temporal -> T(NUM_MONEDAS)  En este caso O(1) -> Solo se repite 8 veces el for, para el numero de monedas
Espacial -> O(1) 

*/


int main(void)
{

    while (true)
    {
        int dinero = 0;

        cin >> dinero;

        
        if (dinero < 0) break;
        
        int monedas[NUM_MONEDAS] = { 500, 200, 100, 50, 25, 10, 5, 1 };
        int cantidad[NUM_MONEDAS] = { 0, 0, 0, 0, 0, 0, 0, 0 };

        //while(dinero > 0)
        //{ 
            for (int i = 0; i < NUM_MONEDAS; i++)
            {
                int numMonedas = floor(dinero / monedas[i]); // floor en caso de obtener un numero decimal de monedas
                                                             // Se podria quitar porque usamos integers
            
                cantidad[i] += numMonedas;
                dinero -= monedas[i] * numMonedas;
                //cout << resto << " " << dinero << " " << monedas[i] << endl;
            }
        //}

        for (int i = 0; i < NUM_MONEDAS; i++)
        {
            cout << cantidad[i] << " ";
        }
        cout << endl;
    }


    return 0;
}