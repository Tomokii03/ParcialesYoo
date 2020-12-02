#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int a;
   int b=0;
   int n=1;
   int c;
   int d;
   float e=0.0;

   cout<<"Este programa determina la mediana de los datos ingresados por el usuario"<<endl;
   cout<<"Cuantos datos desea ingresar?"<<endl;
   cin>>a;

   float arreglo[a];

   while (b<a)
   {
       cout<<"Ingrese el "<<n<<" numero"<<endl;
       cin>>arreglo[b];
       b++;
       n++;
   }
   
   for (int i=0; i<a; i++)
   {
       for (int j=i+1; j<a; j++)
       {
           if (arreglo[i] > arreglo[j])
           {
               c=arreglo[i];
               arreglo[i]=arreglo[j];
               arreglo[j]=c;
               
           }
       }
   }

   for (int r = 0; r < a; r++)
   {
       cout<<arreglo[r]<<endl;
   }
   
   d=a/2;
   if (a%2==0)
   {
       e=(arreglo[d-1]+arreglo[d])/2.0;
   }
   else
   {
       e=arreglo[d];
   }

   cout<<"La mediana es: "<<e<<endl;
   

}