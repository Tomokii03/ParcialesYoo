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
   float desviacion;
   float m=1/2;
   int t;

   cout<<"Este programa calcula la desviacion estandar"<<endl;
   cout<<"ingrese numero total de datos"<<endl;
   cin>>a;
   float arreglo1[a];
   float arreglo2[a];
   while(b<a)
   {
      cout<<"Ingrese el "<<c<<" dato"<<endl;
      cin>>arreglo1[b];
      suma=suma+arreglo1[b];
      b=b+1;
      c=c+1;
   }
   media=suma/a;
   cout<<media<<endl;
   while(t<a)
   {
       arreglo2[t]=arreglo1[t]-media;
       d=pow(arreglo2[t],2);
       e=e+d;
       t=t+1;
   }
   desviacion=sqrt(e/(a-1));
   cout<<"La desviacion estandar es de: "<<desviacion<<endl;

}