#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int arreglo[5][5],a=0,b=0,c=0,d=0,e,f,x=0;

   cout<<"La siguiente matriz es un parqueadero y puede agregar un vehiculo si quiere"<<endl;
   cout<<"0 son los espacios basios"<<endl;
   cout<<"1 son los lugares que tienen una moto"<<endl;
   cout<<"2 son los lugares que tienen un sedan de 5 puestos"<<endl;
   cout<<"3 son los lugares que tienen un auto de 7 pasajeros"<<endl;
   cout<<endl;

   for(int i=0; i<5; i++)
   {
       for(int j=0; j<5; j++)
       {
           arreglo[i][j]=rand()%(0-4);
           cout<<arreglo[i][j]<<" ";
           if (arreglo[i][j]==0)
           {
               a=a+1;
           }
           if (arreglo[i][j]==1)
           {
               b=b+1;
           }
           if (arreglo[i][j]==2)
           {
               c=c+1;
           }
           if (arreglo[i][j]==3)
           {
               d=d+1;
           }
       }
       cout<<endl;
   }

   while(x<1)
   {
       cout<<endl;
       cout<<"Hay un total de:"<<endl;
       cout<<a<<" lugares disponibles"<<endl;
       cout<<b<<" motos"<<endl;
       cout<<c<<" sedan de 5 puestos"<<endl;
       cout<<d<<" auto de 7 pasajeros"<<endl;
       cout<<endl;
       cout<<"desea ingresar algun vehiculo?"<<endl;
       cout<<"1-Si"<<endl;
       cout<<"2-no"<<endl;
       cin>>e;
   
       switch (e)
       {
       case 1:
           cout<<"Que tipo de vehiculo desea ingresar?"<<endl;
           cout<<"1-Moto"<<endl;
           cout<<"2-Sedan de 5 puestos"<<endl;
           cout<<"3-Carro de 7 puestos"<<endl;
           cin>>f;
           cout<<endl;
           for(int i=0; i<5; i++)
           {
               for(int j=0; j<5; j++)
               {
                   if(arreglo[i][j]==0)
                   {
                        arreglo[i][j]=f;
                        i=4;
                        j=4;
                   }
               }
           }
           a=0;
           b=0;
           c=0;
           d=0;
           for(int i=0; i<5; i++)
           {
               for(int j=0; j<5; j++)
               {
                   cout<<arreglo[i][j]<<" ";
                   if(arreglo[i][j]==0)
                   {
                       a=a+1;
                   }
                   if(arreglo[i][j]==1)
                   {
                       b=b+1;
                   }
                   if(arreglo[i][j]==2)
                   {
                       c=c+1;
                   }
                   if(arreglo[i][j]==3)
                   {
                       d=d+1;
                   }
               }
               cout<<endl;
           }
           break;
       case 2:
            cout<<"Gracias por utilizar el programa"<<endl;
            x=1;
       default:
           cout<<"Seleccion erronea"<<endl;
           break;
       }
       if (a==0)
       {
           cout<<endl;
           cout<<"Hay un total de:"<<endl;
           cout<<a<<" lugares disponibles"<<endl;
           cout<<b<<" motos"<<endl;
           cout<<c<<" sedan de 5 puestos"<<endl;
           cout<<d<<" auto de 7 pasajeros"<<endl;
           cout<<endl;
           cout<<"Ya no hay lugares disponibles"<<endl;
           cout<<"Gracias por utilizar el programa"<<endl;
           x=1;
       }
       
    }
}