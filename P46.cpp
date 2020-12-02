#include <iostream>
#include <math.h>
using namespace std;

float x(int n)
{
   float arreglo[n],arreglo2[n],a=0,b=1,suma=0,d;
   arreglo[0]=1;
   arreglo2[0]=1;
   for(int i=1; i<n; i++)
   {   
       arreglo[i]=a+b;
       arreglo2[i]=arreglo[i];
       a=b;
       b=arreglo[i];   
   }
   for(int i=0; i<n; i++)
   {
      suma=suma+arreglo2[i];
   }
   d=suma/n;
   return d;
}

int main()
{
   int n;
   cout<<"Este programa calcula el promedio de los primeros numeros n numeros de la sucesion de Fibonacci"<<endl;
   cout<<"Ingrese el total de n numeros"<<endl;
   cin>>n;
   cout<<"El promedio de los datos es: "<<x(n)<<endl;
   return 0;
}
