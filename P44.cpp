#include <iostream>
#include <math.h>
using namespace std;

float x(float a, float b, float c, float d)
{
    float r,t;
    r=(1/((1/a)+(1/b)+(1/c)));
    t=d/r;
    return t;
}

float z(float a, float b, float c, float d)
{
    float r,t;
    r=a+b+c;
    t=d/r;
    return t;
}

int main()
{
   int a,b,c,d,e;
   cout<<"Este programa calcula la corriente de un circuito en paralelo o en serie"<<endl;
   cout<<"Ingrese el valor de la primera resistencia"<<endl;
   cin>>a;
   cout<<"Ingrese el valor de la segunda resistencia"<<endl;
   cin>>b;
   cout<<"Ingrese el valor de la tercera resistencia"<<endl;
   cin>>c;
   cout<<"Ingrese el valor de la fuente de tension"<<endl;
   cin>>d;
   cout<<"Como se encuentra el circuito?"<<endl;
   cout<<"1-Serie"<<endl;
   cout<<"2-Paralelo"<<endl;
   cin>>e;
   switch (e)
   {
   case 1:
       cout<<"La corriente es de: "<<z(a,b,c,d)<<"A"<<endl;
       break;
   case 2:
       cout<<"La corriente es de: "<<x(a,b,c,d)<<"A"<<endl;
       break;
   default:
       cout<<"Seleccion erronea"<<endl;
       break;
   }
}

