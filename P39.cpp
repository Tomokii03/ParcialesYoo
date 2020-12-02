#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n=5,b=3;
   cout<<"Este programa multiplica una matriz por un escalar"<<endl;
   int arreglo[n][n];
   int a[n][n];
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           arreglo[i][j]=rand()%(1-9);
           a[i][j]=arreglo[i][j]*b;
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
