#include <iostream>
#include <math.h>
using namespace std;

float x(float n, float a)
{
    float b;
    b=n/a;
    return b;
}

int main()
{
   int n,a;
   cout<<"Este programa calcula la corriente"<<endl;
   cout<<"Ingrese el valor de la tension"<<endl;
   cin>>n;
   cout<<"Ingrese el valor de la resistencia"<<endl;
   cin>>a;
   cout<<"El valor de la corriente es: "<<x(n,a)<<endl;
   return 0;
}

