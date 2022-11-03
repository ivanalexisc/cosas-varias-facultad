/*19. Se dispone de los 12 archivos mensuales de los proveedores de la empresa textil. Informar el
total anual que proveyó por cada tipo de lana cada uno de los criaderos.
Tip: Use concatenación de string para formar el nombre del archivo.
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
for (int i = 0; i <12; i++)
{
    archivo.open("PROVEEDORES_" + i + ".TXT");
}




    return 0;
}
