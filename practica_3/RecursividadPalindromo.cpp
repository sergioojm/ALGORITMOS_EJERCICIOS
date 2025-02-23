#include <iostream>
#include <string>

#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}
#define MAX_TAM_PALABRA 20

using namespace std;


/*

    Precondiciones: Palabra sea menor que el tamaño indicado
    Complejidad Temporal: O(n)
    Complejidad Especial O: O(n)
    Complejidad Especial M: M(1) = 1, M(n) = M(n-2) + 1
    Complejidad Temporal T: T(1) = 1, T(n) = T(n-2) + 1

*/

int isPalindromo(string palabro, int init, int fin);

int main(void)
{

    std::string palabra (" ");

    cin >> palabra;
    
    assertdomjudge(palabra.length() <= MAX_TAM_PALABRA);

    int res = isPalindromo(palabra, 0, palabra.length() - 1);

    cout << res;

    return 0;
}


int isPalindromo(string palabro, int init, int fin)
{

    if (init >= fin)
    {
        return 1;
    }

    if (palabro[init] != palabro[fin])
    {
        return 0;
    }

    return isPalindromo(palabro, init + 1, fin - 1);
}