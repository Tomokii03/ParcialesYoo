#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n=5;
   cout<<"Este programa multiplica dos matrices"<<endl;
   int arreglo[n][n];
   int arreglo2[n][n];
   int a[n][n];
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           arreglo[i][j]=rand()%(1-9);
           arreglo2[i][j]=rand()%(1-9);
       }
   }
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           a[i][j]=0;
           for(int k=0; k<n; k++)
           {
               a[i][j]=arreglo[i][k]*arreglo2[k][j]+a[i][j];
           }
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
           cout<<arreglo2[i][j]<<" ";
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
