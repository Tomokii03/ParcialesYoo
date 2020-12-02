#include <iostream>
#include <string>

using namespace std;

struct Estudiante
{
    string Nombre;
    string Apellido;
    int DocumendoDeIdentidad;
    int Edad;
    string SemestreAcademico;
};

int main()
{
    Estudiante A;
    A.Nombre = "Andres";
    A.Apellido = "Navarrete";
    A.DocumendoDeIdentidad = 1007524122;
    A.Edad = 19;
    A.SemestreAcademico = "Cuarto Semestre";

    cout<<"El nombre es: "<<A.Nombre<<endl;
    cout<<"El Apellido es: "<<A.Apellido<<endl;
    cout<<"Su documento de Identidad es: "<<A.DocumendoDeIdentidad<<endl;
    cout<<"Su edad es: "<<A.Edad<<endl;
    cout<<"En el semestre que esta actualmente es el: "<<A.SemestreAcademico<<endl;
    

    return 0;
}
