/*18. Una empresa textil, dedicada al hilado de lana ovina, recibe su materia prima de distintos
criaderos de ovejas distribuidos en el país.
Mensualmente, se ingresan sin orden alguno, los siguientes datos de los N criaderos de oveja: Nro
de criadero (de 1 a N), tipo de oveja (1: Merino, 2: Texel, 3: Dorset), cantidad de kilos lana. Se sabe
que puede venir más de una entrada de lana, para un mismo criadero y un mismo tipo de oveja.
También puede ser que algún criadero no haya enviado alguno de los tipos de lana. El fin de datos
está dado por Nro de criadero = 999.
El valor N y el número de mes, se ingresan como primeros datos.
Generar un archivo “PROVEEDORES_XX.TXT” con la información Nro Criadero | Kilos Merino | Kilos
Texel | Kilos Dorset. Donde XX representa el número de mes.*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{

    ofstream archivo;
    string mes;
    int n;
    cout << "Ingresar mes: " << endl;
    getline(cin,mes);
    cout << "Ingresar valor n: " << endl;
    cin >>n;

    archivo.open("./PROVEEDORES_" + mes + ".txt");

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }
    int tipo,numCria,cantK;
    int mat[n][3]; // [0 merino] [1Texel ] [2Dorset]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = 0;
        }

    }


    cout << "Ingresar numero de criadero: " << endl;
    cin >>numCria;
    while (numCria != 999)
    {
        cout << "Ingresar tipo de oveja (1: Merino, 2: Texel, 3: Dorset): " << endl;
        cin >>tipo;
        cout << "Ingresar cantidad de kilos de lana: " << endl;
        cin >>cantK;

        mat[numCria][tipo - 1] += cantK;

        cout << "Ingresar numero de criadero: " << endl;
        cin >> numCria;
    }

    for (int i = 0; i < n; i++)
    {
        archivo << i << " | " << mat[i][0] << " | " << mat[i][1] << " | " << mat[i][2] << endl;
    }


    archivo.close();
    return 0;
}