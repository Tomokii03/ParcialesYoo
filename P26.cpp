#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int ax;
   int bx=0;
   int cx=1;
   int sumax;
   float media;
   float d;
   float e=0;
   float desviacion;
   int t;
   int v=0;
   int w=0;
   int moda;
   float sesgo;

   cout<<"Este programa calcula el Sesgo"<<endl;
   cout<<"ingrese numero total de datos"<<endl;
   cin>>ax;
   int arreglo[ax];

   //Media aritmetica
   while(bx<ax)
   {
      cout<<"Ingrese el "<<cx<<" dato"<<endl;
      cin>>arreglo[bx];
      sumax=sumax+arreglo[bx];
      bx=bx+1;
      cx=cx+1;
   }
   media=sumax/ax;
   cout<<"La media aritmetica es: "<<media<<endl;

   //Desviacion estandar
   float arreglo2[ax];

   while(t<ax)
   {
       arreglo2[t]=arreglo[t]-media;
       d=pow(arreglo2[t],2);
       e=e+d;
       t=t+1;
   }
   desviacion=sqrt(e/(ax-1));
   cout<<"La desviacion estandar es de: "<<desviacion<<endl;

   //Moda
   for (int i=0; i<ax; i++)
   {
       for (int j=0; j<ax; j++)
       {
           if (arreglo[j]==arreglo[i])
           {
               v=v+1;
           }
       }
       if (v>w)
       {
           w=v;
           moda=arreglo[i];
       }
       v=0;
   }
    cout<<"La moda es: "<<moda<<endl;
    sesgo=(media-moda)/desviacion;
    cout<<"El sesgo es de: "<<sesgo<<endl;
}