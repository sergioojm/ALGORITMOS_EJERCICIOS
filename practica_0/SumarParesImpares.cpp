#include <iostream>

using namespace std;


int main()
{

    int a = 0;
    int result = 0;

    cin >> a;

    if (a % 2 == 0)
    {
        for (int i = 0; i <= a; i++)
        {
            if (i % 2 == 0)
            {
                result += i;
            }
        }
    }
    else
    {
        for (int i = 0; i <= a; i++)
        {
            if (i % 2 == 1)
            {
                result += i;
            }
        }
    }

    cout << result;

    return 0;
}