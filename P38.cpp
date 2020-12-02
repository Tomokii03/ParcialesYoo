#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n=5;
   cout<<"Este programa saca la transpuesta de una matriz"<<endl;
   int arreglo[n][n];
   int a[n][n];
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           arreglo[i][j]=rand()%(1-9);
       }
   }
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           a[j][i]=arreglo[i][j];
       }
   }
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           cout<<arreglo[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   cout<<endl;
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }
}
