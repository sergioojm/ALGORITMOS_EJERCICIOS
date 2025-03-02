#include<iostream>

using namespace std;


int* merge(int left[], int right[], int leftLength, int rightLength)
{
    int* result = new int[leftLength + rightLength]; 

    int leftPointer = 0;
    int rightPointer = 0;
    int resultPointer = 0;

    while (leftPointer < leftLength && rightPointer < rightLength)
    {
        if (left[leftPointer] <= right[rightPointer])
        {
            result[resultPointer++] = left[leftPointer++];
        }
        else
        {
            result[resultPointer++] = right[rightPointer++];
        }
    }


    while (leftPointer < leftLength)
    {
        result[resultPointer++] = left[leftPointer++];
    }

  
    while (rightPointer < rightLength)
    {
        result[resultPointer++] = right[rightPointer++];
    }

    return result;
}

/*


T(1) = 1, T(n) = 2*T(n/2) +n + 1
O(n log n) temporal
O(n) espacial

*/

int* ordenarMergeSort(int x[], int len)
{
    if (len <= 1)
    {
        return x;
    }

    int medio = len / 2;


    int* left = new int[medio];
    int* right = new int[len - medio];

    for (int i = 0; i < medio; i++)
    {
        left[i] = x[i];
    }

    for (int i = medio; i < len; i++)
    {
        right[i - medio] = x[i];
    }

    left = ordenarMergeSort(left, medio);
    right = ordenarMergeSort(right, len - medio);

    // optimizacion en caso de haber ordenado ya los array, acorde al pseudocodigo de wikipedia
    if (left[medio - 1] <= right[0])
    {
        int* result = new int[len];
        for (int i = 0; i < medio; i++) result[i] = left[i];
        for (int i = 0; i < len - medio; i++) result[medio + i] = right[i];


        for (int k = 0; k < len; k++)
        {
            x[k] = result[k];
            cout << x[k] << " ";
        }
        cout << endl;
        
        delete[] left;
        delete[] right;

        return result;
    }


    int* sortedArray = merge(left, right, medio, len -  medio);

    for (int k = 0; k < len; k++)
    {
        x[k] = sortedArray[k];
        cout << x[k] << " ";
    }
    cout << endl;

    delete[] left;
    delete[] right;

    return sortedArray;
}



int main(void)
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarMergeSort(x,n);
}

