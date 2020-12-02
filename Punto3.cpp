#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cout<<"Bienvenido"<<endl;
    cout<<"Por favor ingrese la cantidad de valores que desee: "<<endl;
    cin>>n;

    float A[n];
    float *Tomokii=&A[0];
    float Mediana;

    for (int i=0; i<n; i++)
    {
        cout<<"Ingrese los numeros a los cuales le quiera sacar la mediana: "<<endl;
        cin>>Tomokii[i];
    }

    if ((n%2)==1)
        Mediana=Tomokii[n/2];
    else
        Mediana=(Tomokii[n/2]+Tomokii[n/2-1])/2;

    cout<<"Mediana: "<<Mediana<<endl;    
}