#include <iostream>

using namespace std;

int main()
{
   int a;
   int b=0;
   int c=1;
   int e;
   int suma=0;
   
   cout<<"Este programa determine cuales numeros son pares"<<endl;
   cout<<"Ingrese la cantidad de numeros a ingresar"<<endl;
   cin>>a;
   e=a;
   a=a-1;
   int arreglo[a];

   while(c<=e)
   {
       cout<<"Ingrese el "<<c<<" numero"<<endl;
       cin>>arreglo[b];
       if(arreglo[b]%2==0)
       {
           cout<<">"<<arreglo[b]<<" es par"<<endl;
       }
       else
       {
           cout<<">"<<arreglo[b]<<" es impar"<<endl;
       }
       
       c=c+1;
       b=b+1;
   }
}