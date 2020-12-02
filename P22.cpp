#include <iostream>

using namespace std;

int main()
{
   int a;
   int b=0;
   int c=1;
   int suma;
   float media;

   cout<<"Este programa calcula la media aritmetica"<<endl;
   cout<<"ingrese numero total de datos"<<endl;
   cin>>a;
   int arreglo[a];
   while(b<a)
   {
      cout<<"Ingrese el "<<c<<" dato"<<endl;
      cin>>arreglo[b];
      suma=suma+arreglo[b];
      b=b+1;
      c=c+1;
   }
   media=suma/a;
   cout<<"La media aritmetica es: "<<media<<endl;
}