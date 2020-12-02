#include <iostream>
#include <math.h>
using namespace std;

void x(float a, float &b, float &c)
{
   b=a/(2*3.14);
   c=3.14*pow(b,2);
}

int main()
{
   float a,b,c;
   cout<<"Este programa calcula el radio y el area de un circulo por medio del perimetro"<<endl;
   cout<<"Ingrese el perimetro"<<endl;
   cin>>a;
   x(a,b,c);
   cout<<"El radio es de: "<<b<<endl;
   cout<<"El area es igual a: "<<c<<endl;
}
