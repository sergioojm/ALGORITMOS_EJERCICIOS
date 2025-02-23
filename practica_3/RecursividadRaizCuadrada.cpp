#include <iostream>
#include <cmath> // Para abs()

#define assertdomjudge(x) if (!(x)){std::cout << "ERROR" << std::endl;exit(0);}

/*

    Precondiciones: numero y el error han de ser positivos y distinto de 0

*/

using namespace std;

double squareRootAproximation(float error, float target, float max, float min) 
{
    double meanTarget = (min + max) / 2;

    if (abs((meanTarget * meanTarget) - target) < error) 
    {
        return meanTarget;
    }

    cout << meanTarget << endl;

    if ((meanTarget * meanTarget) > target) 
    {
        return squareRootAproximation(error, target, meanTarget, min);
    }
    else 
    {
        return squareRootAproximation(error, target, max, meanTarget);
    }
}

int main() 
{
    float numero, error;

    cin >> numero >> error;

    assertdomjudge(numero > 0);
    assertdomjudge(error > 0);

    double resultado = squareRootAproximation(error, numero, numero, 0.0);

    cout << resultado << endl;

    return 0;
}
