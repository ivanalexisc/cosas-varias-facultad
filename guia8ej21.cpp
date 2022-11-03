/*21. Se dispone de la información de un grupo de empleados de una empresa. Se desea generar un
archivo de texto que contenga: dni ; sexo (‘M’ o ‘F’) ; sueldo ; cuil. Los datos se ingresan sin orden.
Un DNI igual a 0 indica el fin de datos.
El archivo se debe llamar EMPLEADOS.CSV. La información de cada empleado se graba en un
mismo renglón, separado por ;*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
long long dni,cuil,sueldo,i=0;
char sexo;
ofstream archivo;
archivo.open("./EMPLEADOS.CSV");
if (archivo.fail())
{
    cout << "ERRORRRRR!!!!" << endl;
}

cout << "ingrese el dni :" << endl;
cin>>dni;
while (dni !=0)
{
    
    cout << "Ingrese el sexo : " << endl;
    cin>>sexo;
    cout << "Ingrese el sueldo : " << endl;
    cin>>sueldo;
    cout << "Ingrese el cuil : " << endl;
    cin>>cuil;
    
    archivo<<dni<<";"<<sexo<<";"<<sueldo<<";"<<cuil<<endl;

    cout << "ingrese el dni :" << endl;
    cin>>dni;

    
}

archivo.close();

    return 0;
}