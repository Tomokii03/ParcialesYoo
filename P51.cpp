#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   float a,b,c,d,e;
   cout<<"Este programa soluciona una ecuacion cuadratica"<<endl;
   cout<<"Ingrese el valor de X"<<endl;
   cin>>a;
   cout<<"Ingrese el valor de Y"<<endl;
   cin>>b;
   cout<<"Ingrese el valor de C"<<endl;
   cin>>c;
   d=((-b+(sqrt(pow(b,2)-(4*a*c))))/2*a);
   e=((-b-(sqrt(pow(b,2)-(4*a*c))))/2*a);

   cout<<"x="<<d<<endl;
   cout<<"x="<<e<<endl;
}
