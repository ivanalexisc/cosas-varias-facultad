/*11. Se dispone del archivo PRODUCTOS_EN_DOLARES.TXT que tiene la información: cod de
producto, descripción y precio en dólares (provisto por la cátedra). Cada uno de los datos se
encuentra en un renglón (los datos de 1 producto ocupan 3 renglones).
Se solicita generar un archivo PRODUCTOS_EN_PESOS.TXT, que posea la misma estructura que
el archivo anterior pero con el precio transformado a pesos.
La cotización del dólar se ingresa al principio.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ifstream archivoDolares;
ofstream archivoPesos;
int codigo,cotizacion;
string producto;
int precioEnDolares;
archivoDolares.open("PRODUCTO_EN_DOLARES.TXT");
archivoPesos.open("PRODUCTOS_EN_PESOS.TXT");
if (archivoDolares.fail() && archivoPesos.fail())
{
    cout << "ERROR" << endl;
}
cout << "Ingrese la cotizacion del dolar : " << endl;
cin>>cotizacion;
while (!archivoDolares.eof())
{
    archivoDolares>>codigo;
    archivoDolares>>producto;
    archivoDolares>>precioEnDolares;
    archivoPesos<<codigo<<endl;
    archivoPesos<<producto<<endl;
   
    archivoPesos<<precioEnDolares * cotizacion<<endl;
    
}


archivoDolares.close();
archivoPesos.close();




    return 0;
}