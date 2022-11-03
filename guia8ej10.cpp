/*Se desea realizar un informe ordenado por el sueldo a percibir por cada empleado de mayor a
menor con la información existente en el archivo SUELDOS.TXT.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ifstream archivo;
int codigoEmpleado[100];
float sueldo[100];
int cantidad=0,aux,aux2;
archivo.open("./SUELDOS.TXT");
if (archivo.fail())
{
    cout << "ERROR" << endl;
}
archivo>>codigoEmpleado[cantidad];
while (!archivo.eof())
{
    archivo>>sueldo[cantidad];
     archivo.ignore();
     cantidad++;
     archivo>>codigoEmpleado[cantidad];
}
for (int i = 0; i <cantidad; i++)
{
    for (int j = i+1; j < cantidad; j++)
    {
        if (sueldo[i]<sueldo[j] && codigoEmpleado[i]<codigoEmpleado[j])
        {
            aux = sueldo[i];
            sueldo[i]=sueldo[j];
            sueldo[j] = aux;

            aux2 = codigoEmpleado[i];
            codigoEmpleado[i]=codigoEmpleado[j];
            codigoEmpleado[j] = aux2;
        }
        
    }
   
    
}
 for (int i = 0; i <cantidad; i++)
    {
        cout << codigoEmpleado[i]<< " "<<sueldo[i] <<endl;
    }

archivo.close();


    return 0;
}