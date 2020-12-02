#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int a;
   int b=0;
   int c=1;
   float m=1;
   float r;
   int d;

   cout<<"Este programa calcula la media geometrica"<<endl;
   cout<<"Ingrese el numero total de datos"<<endl;
   cin>>a;
   d=a;

   float arreglo[a];

   while (b<a)
   {
       cout<<"Ingrese el "<<c<<" numero"<<endl;
       cin>>arreglo[b];
       m=m*arreglo[b];
       b=b+1;
       c=c+1;
   }
   r=pow(m,(double)1/d);
   cout<<"La media geometrica es de: "<<r<<endl;

}