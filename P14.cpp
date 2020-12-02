#include <iostream>

using namespace std;

int main()
{
   float arreglo[24];
   int b=0;
   int c=1;
   int d=0;
   int e;

   cout<<"Este programa le permite ingresar las temperaturas de las 24 horas, y consultar la que desee"<<endl;
   
   while(b<24)
   {
       cout<<"Ingrese temperatira "<<c<<endl;
       cin>>arreglo[b];
       b=b+1;
       c=c+1;
   }

   while(d==0)
   {
       cout<<"Desea conocer alguna temperatura?"<<endl;
       cout<<"1. Si"<<endl;
       cout<<"2. No"<<endl;
       cin>>e;
       switch (e)
       {
       case 1:
           cout<<"Que hora del dia desea consultar?"<<endl;
           cin>>b;
           b=b-1;
           cout<<"La temperatura es de: "<<arreglo[b]<<" grado"<<endl;
           break;
       case 2:
           d=d+1;
           break;
       default:
           cout<<"Opcion invalida"<<endl;
           d=d+1;
           break;
       }
   }
   cout<<"Gracias por utilizar nuestro programa"<<endl;
}