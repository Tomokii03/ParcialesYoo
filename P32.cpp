#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int a,b;

   cout<<"Este programa genera una matriz de dimensiones ingresadas"<<endl;
   cout<<"Ingrese el numero de filas"<<endl;
   cin>>a;
   cout<<"Ingrese el numero de columnas"<<endl;
   cin>>b;

   int arreglo[a][b];

   for(int i=0; i<a; i++)
   {
       for(int j=0; j<b; j++)
       {
           arreglo[i][j]=1+rand()%(1-50);
           cout<<arreglo[i][j]<<" ";
       }
       cout<<endl;
   }
}