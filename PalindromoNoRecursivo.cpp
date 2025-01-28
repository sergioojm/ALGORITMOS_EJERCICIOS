#include <iostream>
#include <string>

using namespace std;


int main()
{

    std::string palabra (" ");

    cin >> palabra;

    int res = 1;
    int finalWord = palabra.length() - 1;

    for (int i = 0; i < palabra.length(); i++)
    {
        //cout << "Primera letra -> " << palabra[i] << " | final word -> " << palabra[finalWord-i];
        if (palabra[i] != palabra[finalWord - i])
        {
            res = 0;
        }
    }

    cout << res;

    return 0;
}