/*Se desea realizar un informe con las cantidades de multas por exceso de velocidad que se labran
en el país durante un mes.
Se cuenta con la información que envían todos los municipios: código de provincia y cantidad de
multas. Un código de provincia igual a 99 indica el fin de datos.
Informe:
Nombre de la Provincia Cantidad de multas
 xxxxxxxxxxxxxxxxxxxx xxxxx
 xxxxxxxxxxxxxxxxxxxx xxxxx
 Total de multas: xxxxx
Utilice el archivo creado en el ejercicio anterior para obtener los nombres de las provincias
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ifstream archivo;
string provincias[24];
int codigoProvincia[24];
int cantidadMultas[24];
int aux=0;
int i;
int totalMultas = 0;
archivo.open("./PROVINCIAS.TXT");

for (int i = 0; i <24; i++)
{
    cantidadMultas[0]; 
}


if (archivo.fail())
{
    cout<<"ERROR"<<endl;
    exit(1);
}


    
     while (!archivo.eof()){
        archivo >> codigoProvincia[aux];
        archivo.ignore();
        getline(archivo,provincias[aux]);
        aux++;
    }


cout<<"Ingrese el codigo de provincia"<<endl;
cin>>aux;


    while (aux != 99)
        {
           
            cout<<"Ingrese la cantidad de multas"<<endl;
            cin>>cantidadMultas[aux];

           
            cout<<"Ingrese el codigo de provincia"<<endl;
            cin>>aux;
        }
 cout<<"Nombre de la provincia: "<<" "<<"Cantidad de multas"<<endl;
for (int i = 0; i <24; i++)
{
    cout<<provincias[i]<<" "<<cantidadMultas[i]<<endl;
    totalMultas+=cantidadMultas[i];
}
cout<<"Cantidad total de multas : "<<totalMultas;

archivo.close();


    return 0;
}