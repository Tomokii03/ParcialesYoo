#include <iostream>
#include <math.h>
using namespace std;

void x(int a, int b, int c, int &mayor, int &menor)
{
   for(int i=0; i<3 ;i++)
   {
       if (a<b)
       {
           if(a<c)
           {
               menor=a;
           }
       }
       if (b<a)
       {
           if(b<c)
           {
               menor=b;
           }
       }
       if (c<a)
       {
           if(c<b)
           {
               menor=c;
           }
       }
   }

   for(int i=0; i<3 ;i++)
   {
       if (a>b)
       {
           if(a>c)
           {
               mayor=a;
           }
       }
       if (b>a)
       {
           if(b>c)
           {
               mayor=b;
           }
       }
       if (c>a)
       {
           if(c>b)
           {
               mayor=c;
           }
       }
   }
}

int main()
{
   int a,b,c,mayor,menor;
   cout<<"Este programa pide tres numeros y muestra el mayor y el menor dato ingresado"<<endl;
   cout<<"Ingrese el primer numero"<<endl;
   cin>>a;
   cout<<"Ingrese el segundo numero"<<endl;
   cin>>b;
   cout<<"Ingrese el tercer numero"<<endl;
   cin>>c;
   x(a,b,c,mayor,menor);
   cout<<"El dato mayor es: "<<mayor<<endl;
   cout<<"El dato menor es: "<<menor<<endl;
}
