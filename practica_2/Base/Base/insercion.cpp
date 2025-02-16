#include<iostream>
using namespace std;

/*

  Precondicion: N/A
  T(n) = (n^2 / 2) + (n / 2) + 1
  Complejidad Temporal = O(n^2)
  Complejidad Espacial = O(1)

*/

void ordenarInsercion(int x[],int len)
{
  for(int i=1;i<len;i++)
    {
      int key = x[i];

      int j = i - 1;

      while (j >= 0 && x[j] > key)
      {
        x[j + 1] = x[j];
        j--;
      }
      x[j + 1] = key;
   
      /*Añadir código de ordenación mediante inserción*/
      
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
   cin>>x[i];
 ordenarInsercion(x,n);
}


