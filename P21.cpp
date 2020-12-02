#include <iostream>

using namespace std;

int main()
{
   int a[10];
   int b=0;
   while(b<10)
   {
       a[b]=rand();
       cout<<a[b]<<endl;
       b=b+1;
   }
}