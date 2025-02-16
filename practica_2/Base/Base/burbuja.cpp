#include <iostream>

using namespace std;

/*

  Precondicion: N/A
  T(n) = (n^2 / 2) + (n / 2) + 1
  Complejidad Temporal = O(n^2)
  Complejidad Espacial = O(1)

*/

void ordenarBurbuja(int x[],int len)
{
  for(int i=1;i<len;i++)
  {

    /*Añadir código de ordenación usando algoritmo de burbuja*/
    for (int j = 0; j < len - i; j++)
    {
      if (x[j] > x[j + 1])
      {
        int temp = x[j];
        x[j] = x[j+1];
        x[j+1] = temp;
      }
    }


    for(int k=0;k<len;k++)
    {
      cout<<x[k]<<" ";
    }
    cout<<endl;
  }  
}


int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
 {
  cin>>x[i];
 }
 ordenarBurbuja(x,n);
}
