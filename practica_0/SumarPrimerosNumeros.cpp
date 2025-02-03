#include <iostream>

using namespace std;


int main()
{

    int a = 0;
    int res = 0;
    
    cin >> a;

    for (int i = 0; i <= a; i++)
    {
        res += i;
    }

    cout << res;

}