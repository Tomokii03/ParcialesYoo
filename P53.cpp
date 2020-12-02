#include <iostream>
#include <math.h>
using namespace std;

void x(double a, double b, double &c, double &d)
{
   c=sqrt(pow(a,2)+pow(b,2));
   d=atan(b/a);
}

int main()
{
   double a,b,c,d;
   cout<<"Este programa convierte una cordenada de cartesiana a polar"<<endl;
   cout<<"Ingrese X"<<endl;
   cin>>a;
   cout<<"Ingrese Y"<<endl;
   cin>>b;
   x(a,b,c,d);
   cout<<"El valor en polar es de: ("<<c<<","<<d<<")"<<endl;
}
