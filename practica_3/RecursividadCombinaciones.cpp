#include <iostream>
#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}

using namespace std;

int getCombinations(int n, int r);
int factorialRecursivo(int numero);

/*

    Precondiciones: n y r numeros naturales, y r > n
    Complejidad Temporal: O(n)
    Complejidad Especial: O(n)
    Complejidad Temporal T: 

*/

int main(void)
{
    int n, r;

    while(true)
    {
      

        cin >> n;
        cin >> r;
    
        if (n < 0 || r < 0) break;
        
        // Validaciones de precondiciones
        if (r > n) {
            cout << "ERROR" << endl;
            continue;
        }
    
        cout << getCombinations(n, r) << endl;
    }

  

    return 0;
}

int getCombinations(int n, int r)
{
    return factorialRecursivo(n) / (factorialRecursivo(r) * factorialRecursivo(n - r));
}

int factorialRecursivo(int numero)
{
    if (numero <= 1)
    {
        return 1;
    }

    return numero * factorialRecursivo(numero - 1);
}