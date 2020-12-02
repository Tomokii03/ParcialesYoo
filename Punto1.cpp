#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i , j; 
    float Mayor=0 , Menor=0;

    cout<<"Bienvenido"<<endl;
    cout<<"Por favor ingrese el numero que desea de filas y columnas: "<<endl;
    cin>>n;
    int Arreglo[n][n];

    cout<<"Escribir numeros: "<<endl;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
        {
            cin>>Arreglo[i][j];
        }

    }

    cout<<"Impresion de Arreglo: "<<endl;
    for(i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
        {
            cout<<Arreglo[i][j]<<" ";
        }
        cout<<endl;
    }    
    
    Menor=Arreglo[0][0];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(Menor>Arreglo[i][j])
            {
                Menor=Arreglo[i][j];
            }
        }
    }

    cout<<"El Menor valor es: "<<Menor<<endl;

    Mayor=Arreglo[0][0];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(Mayor<Arreglo[i][j])
            {
                Mayor=Arreglo[i][j];
            }
        }
    }

    cout<<"El Mayor valor es: "<<Mayor<<endl;

    cout<<"El Promedio es: "<<(Mayor+Menor)/2<<endl;


    return 0;
}
