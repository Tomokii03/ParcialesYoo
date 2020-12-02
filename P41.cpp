#include <iostream>
#include <math.h>
using namespace std;

int x(int n)
{
    int b=1;
    while(n!=0)
    {
        b=b*n;
        n=n-1;
    }
    return b;
}

int main()
{
   int n;
   cout<<"Este programa calcula el factorial de un numero"<<endl;
   cout<<"Ingrese un numero"<<endl;
   cin>>n;
   cout<<x(n)<<endl;
   return 0;
}

