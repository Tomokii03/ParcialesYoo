#include <iostream>
#include <math.h>
using namespace std;

void x(float a, float &b, float &c)
{
   b=a*0.00028;
   c=a*0.00023;
}

int main()
{
   float a,b,c;
   cout<<"Este programa convertidor de divisas, de peso a dolar y euro"<<endl;
   cout<<"Ingrese el valor a convertir"<<endl;
   cin>>a;
   x(a,b,c);
   cout<<"Dolares: "<<b<<endl;
   cout<<"Euros: "<<c<<endl;
}
