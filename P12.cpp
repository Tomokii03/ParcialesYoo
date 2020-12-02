#include <iostream>

using namespace std;

int main()
{
   float arreglo[100];
   int b=0;
   int c=0;
   
   while(b<100)
   {
       arreglo[b]=c;
       cout<<arreglo[b]<<endl;
       b=b+1;
       c=c+2;
   }
}