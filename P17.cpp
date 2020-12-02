#include <iostream>

using namespace std;

int main()
{
   int a;
   int b=0;
   int c=1;
   int suma=0;
   
   cout<<"Este programa suma numeros negativos de 0 hasta un valor ingresado por el usuario"<<endl;
   cout<<"Ingrese un valor"<<endl;
   cin>>a;
   int arreglo[a];

   while(c<=a)
   {
       arreglo[b]=c;
       cout<<arreglo[b]<<endl;
       suma=suma+arreglo[b];
       c=c+2;
       b=b+1;
   }
   cout<<"La suma de todos los numeros impares es de: "<<suma<<endl;

}