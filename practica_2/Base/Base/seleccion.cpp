#include<iostream>
using namespace std;

void ordenarSeleccion(int x[],int len)
{
  for(int i=0;i<len;i++)
    {
      /*Añadir código de ordenar mediante selección */
      
      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
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
 ordenarSeleccion(x,n);
}

