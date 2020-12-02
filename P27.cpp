#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int a;
   int b=0;
   float c=1;
   float suma;
   float media;
   float d;
   float e=0;
   float f=0;
   float varianza;
   float m=1/2;
   int t;
   float curtosis;

   cout<<"Este programa calcula la cuartosis"<<endl;
   cout<<"ingrese numero total de datos"<<endl;
   cin>>a;
   float arreglo1[a];
   float arreglo2[a];
   float arreglo3[a];
   while(b<a)
   {
      cout<<"Ingrese el "<<c<<" dato"<<endl;
      cin>>arreglo1[b];
      suma=suma+arreglo1[b];
      b=b+1;
      c=c+1;
   }
   media=suma/a;
   while(t<a)
   {
       arreglo2[t]=arreglo1[t]-media;
       d=pow(arreglo2[t],2);
       e=e+d;
       t++;
   }

   for (int i=0; i<a; i++)
   {
       arreglo3[i]=pow(arreglo2[i],(float)4);
       f=f+arreglo3[i];
   }

   varianza=pow((float)e/(a-1),(float)4);
   curtosis=((f/(a*varianza))-3);
   cout<<"El cuartosis es de: "<<curtosis<<endl;
}