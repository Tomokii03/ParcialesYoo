#include <iostream>
#include <math.h>
using namespace std;

float x(float a, float b, float c, float d)
{
    float n;
    n=sqrt(pow(b-a,2)+pow(d-c,2));
    return n;
}

int main()
{
   int a,b,c,d;
   cout<<"Este programa calcula la distancia Euclidiana"<<endl;
   cout<<"Ingrese el valor de X1"<<endl;
   cin>>a;
   cout<<"Ingrese el valor de X2"<<endl;
   cin>>b;
   cout<<"Ingrese el valor de Y1"<<endl;
   cin>>c;
   cout<<"Ingrese el valor de Y2"<<endl;
   cin>>d;
   cout<<"La distancia Euclidiana es de: "<<x(a,b,c,d)<<endl;
   return 0;
}

