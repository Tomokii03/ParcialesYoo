#include <iostream>
#include <math.h>
using namespace std;

float x(float a)
{
    float b;
    b=3.14*pow(a,2);
    return b;
}


int main()
{
   int a;
   cout<<"Este programa calcula el area de un circuilo"<<endl;
   cout<<"Ingrese el radio"<<endl;
   cin>>a;
   cout<<"El radio del ciculo es de: "<<x(a)<<endl;

}

