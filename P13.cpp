#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n=5,b=3;
   cout<<"Este programa multiplica una matriz por un escalar"<<endl;
   int arreglo[n];
   int a[n];
   for(int i=0; i<n; i++)
   {
       arreglo[i]=rand()%(1-9);
       a[i]=arreglo[i]*b;
   }
   for(int i=0; i<n; i++)
   {
        cout<<arreglo[i]<<endl;
   }
   cout<<endl;
   cout<<endl;
   for(int i=0; i<n; i++)
   {
       cout<<a[i]<<endl;
   }
}
