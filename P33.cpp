#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int arreglo[20][2],a=0,b=1;
   arreglo[0][0]=1;
   
   cout<<"Este programa calcula los primeros 20 numeros de la sucecion de Fibonacci"<<endl;
   cout<<arreglo[0][0]<<endl;

   for(int i=1; i<20; i++)
   {
       for(int j=1; j<2; j++)
       {
           arreglo[i][j]=a+b;
           cout<<arreglo[i][j]<<endl;
           a=b;
           b=arreglo[i][j];
       }
   }
}