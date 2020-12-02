#include <iostream>

using namespace std;

int main()
{
   int a;
   int b=0;
   int c=1;
   int d;
   int mayor=0;

   cout<<"Este programa determina el numero mayor ingresado por el usuario"<<endl;
   cout<<"Cuantos numeros ingresara?"<<endl;
   cin>>a;
   d=a;
   a=a-1;

   float arreglo[a];

   while(b<=a)
   {
       cout<<"Ingrese el "<<c<<" numero"<<endl;
       cin>>arreglo[b];
       if(mayor<arreglo[b])
       {
           mayor=arreglo[b];
       }
       b=b+1;
       c=c+1;
   }
   cout<<"El numero mayor ingresado es: "<<mayor<<endl;
}