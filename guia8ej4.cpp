#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

/* 4. El club del ejercicio anterior decide realizar un control estadístico de la cantidad de veces que han
estado detenidos sus integrantes. Para ello use el archivo BARRAS.TXT generado en el ejercicio
anterior.
Informar de acuerdo al siguiente informe:
Cantidad de Detenciones Cantidad de integrantes
1                                 XXXX
2 – 4                             XXXX
5 – 10                            XXXX
más de 10                         XXXX
Cantidad de integrantes de la barra: XXXX
Desean conocer además el apodo del integrante que más detenciones ostenta. */

int main(int argc, char const *argv[])
{
    ifstream archivo;//creamos el archivo de lectura
    string apodo[999];
    int deten[999];
    int cantidad = 0;
    int unaDet = 0;
    int dosCuatroDet = 0;
    int cincoDiezDet = 0;
    int masDiezDet = 0;
    int masDetenciones = 0;
    string apodoMas;

    archivo.open("./guia8_3.txt");//lo abrimos

    if (archivo.fail()){
        cout << "Error!" << endl;
        exit(1);
    }//preguntamos por error

    getline(archivo,apodo[cantidad], '|');
    while (!archivo.eof()){
        archivo >> deten[cantidad];
        archivo.ignore();
        cantidad++;
        getline(archivo,apodo[cantidad], '|');
    }
    
    for (int i = 0; i < cantidad; i++)
    {
        if (deten[i] == 1 && deten[i] < 2 )
        {    
            unaDet++;
        }else if (deten[i] >= 2 && deten[i] <= 4)
        {
            dosCuatroDet++;
        }else if(deten[i] >= 5 && deten[i] <= 10)
        {
            cincoDiezDet++;
        }else if(deten[i] > 10)
        {
            masDiezDet++;
        }

        if (deten[i] > masDetenciones){
            masDetenciones = deten[i];
            apodoMas = apodo[i];
        }
    }
    
    cout << "Integrantes 1 detencion: "<< unaDet << endl;
    cout << "Integrantes 2-4 detenciones: "<< dosCuatroDet << endl;
    cout << "Integrantes 5-10 detenciones: "<< cincoDiezDet << endl;
    cout << "Integrantes mas de 10 detenciones: "<< masDiezDet << endl;

    cout << "Cantidad de integrantes de la barra: "<< cantidad << endl;

    cout << "El integrante con mas detenciones es " << apodoMas << endl;
    
    archivo.close();//cerramos archivo

    return 0;
}