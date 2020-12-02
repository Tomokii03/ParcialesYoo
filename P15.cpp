#include <iostream>

using namespace std;

int main()
{
   float arreglo[10];
   int a=0;
   int b=1;
   int c=0;

   cout<<"Este programa guarda 10 numeros en un arreglo"<<endl;
   while(a<10)
   {
       cout<<"Ingrese el "<<b<<" numero"<<endl;
       cin>>arreglo[a];
       a=a+1;
       b=b+1;
   }
   cout<<"Los numeros almacenados fueron:"<<endl;
   while(c<10)
   {  
       cout<<"-"<<arreglo[c]<<endl;
       c=c+1;
   }
}