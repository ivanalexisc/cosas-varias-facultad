/*14. Se desea generar un archivo con la información de los alumnos de Fundamentos de
Programación. Para ello se ingresa por cada alumno: documento, apellido y nombre, nota del primer
parcial, nota del segundo parcial. El ingreso se realiza sin ningún tipo de orden. Un nro de
documento igual a 0 indica el fin de datos. La información en el archivo “FUPRO_2.TXT” se quiere
guardar ordenada por nro de documento. En el archivo se guardará nro de documento y apellido y
nombre en un renglón, y las notas de los parciales en otro.
Obs: Si un alumno no rindió un parcial, se ingresó un 0 como nota*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ofstream archivo;
long nroDocumento,notaPrimerParcial,notaSegundoParcial;
int cantidad=0;
int i=0,aux;
long alumnos[999][3]; // alumnos[i][0] para nro de documento || alumnos[i][1] nota primer parcial || alumnos[i][2] nota segundo parcial
long auxAlumnos[999][3];
string auxnya[999];
string nya[999];
archivo.open("FUPRO_2.TXT");
for (int i = 0; i <999; i++)
{
    for (int j = 0; j <3; j++)
    {
       alumnos[i][j] = 0;
    }

}

if (archivo.fail())
{
    cout << "ERROR" << endl;
    exit(1);
}
cout<<"Ingrese el numero de documento"<<endl;
cin>>nroDocumento;
while (nroDocumento !=0)
{
    
    alumnos[i][0] = nroDocumento;
     cout << "Ingrese nombre y apellido : " << endl;
     cin.ignore();
    getline(cin,nya[i]); 
    cout << "Ingrese nota del primer parcial : " << endl;
    cin>>alumnos[i][1];
    cout << "Ingrese nota del segundo parcial : " << endl;
    cin>>alumnos[i][2];
    i++;
    cout<<"Ingrese el numero de documento"<<endl;
    cin>>nroDocumento;
    
}


for (int t = 0; t <i; t++)
{
    for (int j = t+1; j <i; j++)
    {
        if (alumnos[t][0]<alumnos[j][0])
        {
            
            

            auxnya[t]= nya[j];     
            auxAlumnos[t][0] = alumnos[j][0];
            auxAlumnos[t][1] = alumnos[j][1];
            auxAlumnos[t][2] = alumnos[j][2];
            
            nya[t]=nya[j];
            alumnos[t][0] = alumnos[j][0];
            alumnos[t][1] = alumnos[j][1];
            alumnos[t][2] = alumnos[j][2];
            
            nya[j]=auxnya[t];
            alumnos[j][0] = auxAlumnos[t][0];
            alumnos[j][1] = auxAlumnos[t][1];
            alumnos[j][2] = auxAlumnos[t][2];
            
        }
        
    }
    
}
for (int t = 0; t <i; t++)
{
    
        archivo<<alumnos[t][0]<<" "<<nya[t]<<endl;
        archivo<<alumnos[t][1]<<" "<<alumnos[t][2]<<endl;
    
    
}




archivo.close();

    return 0;
}