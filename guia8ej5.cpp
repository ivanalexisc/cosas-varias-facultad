/*5. Se necesita generar un archivo con los nombres de las 24 provincias. De acuerdo al orden de
ingreso se les asigna un código (entre 0 y 23).
En el archivo PROVINCIAS.TXT se almacena, por renglón, código y nombre separados por espacio
en blanco.
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ofstream archivo;
string provincia;
archivo.open("./PROVINCIAS.TXT");
if (archivo.fail())
{
    cout<<"ERROR"<<endl;
    exit(1);
}
for (int i = 0; i <24; i++)
{
    cout<<"Ingrese el nombre de la provincia:"<<endl;
    getline(cin,provincia);
    archivo<<i<<" "<<provincia<<endl;
}




    return 0;
}