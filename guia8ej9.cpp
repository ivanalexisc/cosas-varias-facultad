/*9. Una empresa posee N empleados y de cada uno de ellos los siguientes datos: Código de
empleado (numérico), cantidad de horas normales trabajadas, cantidad de horas extras trabajadas.
La cantidad de empleados y el valor de la hora normal de trabajo se leen como primeros datos
Se pide:
- Generar un archivo SUELDOS.TXT donde figure Cod de empleado, sueldo a cobrar.
Tenga en cuenta que las horas extras se pagan el doble que las horas normales de trabajo.
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
int N;
float valorHora;
int codigoEmpleado,horasTrabajadas,horasExtras;
archivo.open("./SUELDOS.TXT");
if (archivo.fail())
{
    cout << "ERROR" << endl;
}

cout << "Ingrese la cantidad de empleados : " << endl;
cin>>N;
cout << "Ingrese el valor de la hora normal de trabajo : " << endl;
cin>>valorHora;
for (int i = 0; i <N; i++)
{
    cout << "Ingrese el codigo de empleado : " << endl;
    cin>>codigoEmpleado;
    cout << "Ingrese la cantidad de horas trabajadas: " << endl;
    cin>>horasTrabajadas;
    cout << "Cantidad de horas extras trabajadas: " << endl;
    cin>>horasExtras;
    archivo<<codigoEmpleado<<" "<<horasTrabajadas*valorHora + (horasExtras*valorHora)*2<<endl;

}

archivo.close();


    return 0;
}