/*Se necesita generar un archivo con la cantidad de detenciones de los integrantes de las barras
bravas de un club. El archivo debe contener la información: apodo y la cantidad de veces que estuvo
detenido.
El final de datos se determina con apodo igual a ‘ZZZ’.
Nombre al archivo “BARRAS.TXT”.
En el archivo se almacena, por renglón, apodo y cantidad de detenciones separados por ‘|’.
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
string apodo;
int detenciones;
archivo.open("./BARRAS.TXT");
if (archivo.fail())
{
    cout<<"ERROR"<<endl;
}

cout<<"Ingrese el apodo del detenido : "<<endl;
getline(cin, apodo);
while (apodo != "ZZZ")
{
    
    cout<<"Ingrese la cantidad de veces que ha sido detenido:"<<endl;
    cin>>detenciones;
    archivo<<apodo<<"|"<<detenciones<<endl;
    cout<<"Ingrese el apodo del detenido:"<<endl;
    cin.ignore();
    getline(cin, apodo);
}




    return 0;
}