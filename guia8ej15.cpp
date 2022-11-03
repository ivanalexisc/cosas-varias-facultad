/*15. Se desea generar un archivo “FUPRO_3.TXT”, actualizando la información del archivo
“FUPRO_2.TXT” luego de rendido el tercer parcial. Por cada alumno que rindió el parcial se ingresa:
nro de documento y nota. Un nro de documento igual a 0 indica el fin de datos. La carga de datos
se realiza sin orden. En el archivo se guardará nro de documento y apellido y nombre en un renglón,
y las notas de los tres parciales en otro.
Realizar una función llamada busqueda_binaria para encontrar el registro correspondiente al
documento ingresado.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

void busqueda_binaria(int matriz[][4], int dnibusc, int i);
int main(int argc, char const *argv[])
{
    ifstream archivo;
    ofstream archivo2;
    long nroDocumento;
    int dni, nota1, nota2, nota3;
    string nombreYApellido;
    int nota3Parcial, i = 0, dnibusc;
    int alumnos[999][4]; // alumnos[i][0] documento|| alumnos[i][1] para nota 1 || alumnos[i][2] para nota 2 || alumnos[i][3] para nota 3
    string nya[999];
    archivo.open("FUPRO_2.TXT");
    archivo2.open("FUPRO_3.TXT");
    if (archivo.fail() && archivo2.fail())
    {
        cout << "ERROR!!!!!!!!!" << endl;
        exit(1);
    }
    for (int i = 0; i < 999; i++)
    {
        for (int j = 0; i < 4; i++)
        {
            alumnos[i][j] = 0;
        }
    }

    while (!archivo.eof())
    {
        archivo >> dni;
        getline(archivo, nombreYApellido);

        archivo >> nota1;
        archivo >> nota2;
        alumnos[i][0] = dni;
        alumnos[i][1] = nota1;
        alumnos[i][2] = nota2;
        nya[i] = nombreYApellido;
        i++;
    }

    int band = 0, pos;
    cout << "Ingrese numero de documento :" << endl;
    cin >> dnibusc;
    while (dnibusc != 0)
    {
        cout << "Ingresar nota 3: " << endl;
        cin >> nota3;
        int j = 0;
        while (j < i)
        {
            if (alumnos[j][0] == dnibusc)
            {
                band = 1;
                pos = j;
                j = i;
            }
            j++;
        }

        if (band == 0)
        {
            cout << "El dato no fue hallado";
        }
        else
        {
            alumnos[pos][3] = nota3;
        };
        cout << "Ingrese numero de documento :" << endl;
        cin >> dnibusc;
    }

    for (int k = 0; k < i; k++)
    {
        archivo2 << alumnos[k][0] << " " << nya[k] << endl;
        archivo2 << alumnos[k][1] << " " << alumnos[k][2] << " " << alumnos[k][3] << endl;
    }
    cout << "Ingrese el dni a buscar : " << endl;
    cin >> dnibusc;
    busqueda_binaria(alumnos, dnibusc, i);

    archivo.close();
    archivo2.close();

    return 0;
}

void busqueda_binaria(int matriz[][4], int dnibusc, int i)
{
    int j = 0, band = 0, pos;

    while (j < i)
    {
        if (matriz[j][0] == dnibusc)
        {
            band = 1;
            pos = j ;
            j = i;
        }
        j++;
    }
    if (band == 0)
    {
        cout << "El dato no fue hallado";
    }
    else
    {
        cout << "Notas del dni : " << matriz[pos][1] << " " << matriz[pos][2] << " " << matriz[pos][3];
    };
}