/*Una empresa seleccionará personas para ocupar ciertos cargos. Para ello, todos los postulantes deberán
efectuar 4 tipos de pruebas: 1: aptitud física, 2: capacidad de adaptación, 3: capacidad operativa y 4:
conocimientos específicos del área.
Los datos de los postulantes se encuentran en un archivo llamado aspirantes.txt y contiene, por cada uno
de ellos: DNI, Apellido y Nombre y Teléfono.
Luego de efectuadas las pruebas, se procede a la carga de los resultados ingresándose por cada
postulante: DNI, y luego, Código de prueba (1 a 4) y puntaje obtenido. Sin orden.
Por último, y mediante una función llamada calc_punt(*), se procede a calcular la puntuación final de cada
postulante. Para ello, debe aplicarse la siguiente fórmula:
aptitud física * 2 + capacidad adaptación * 3 + capacidad operativa * 4 + conocimientos específicos * 5
(*)
Observación: defina el tipo de función y los parámetros necesarios para que la función calc_punt pueda devolver el
puntaje final de los postulantes
Se desea:
a) Listar todos los postulantes, ordenados de manera descendente por puntaje final y según el siguiente
formato:
DNI AF CA CO CI Puntaje Final
xxx xx xx xx xx xxxx
xxx xx xx xx xx xxxx
b) Calcular promedio, valor máximo y valor mínimo de todo el grupo (basados en el puntaje final).
c) Generar un archivo con los siguientes datos de cada postulante: DNI, Apellido y Nombre, Teléfono y
Puntaje Final de aquellos postulantes con puntaje iguales o superiores al promedio calculado en el punto
anterior.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;
void calc_punt(long postulantes[][5],int contarchivo);

int main(int argc, char const *argv[])
{
    ifstream archivo;
    long aspirantes[1000][2];
    string nya_aspirantes[1000];
    long postulantes[1000][5];
    int codPrueba, nota,dni,fila;
    archivo.open("./aspirantes.txt");
    if (archivo.fail())
    {
        cout << "ERROR" << endl;
    }

    int contArchivo = 0;
    archivo >> aspirantes[contArchivo][0];
    while (!archivo.eof())
    {
        archivo.ignore();
        getline(archivo, nya_aspirantes[contArchivo]);
        archivo>>aspirantes[contArchivo][1];
        contArchivo++;

        archivo >> aspirantes[contArchivo][0];
    }
    archivo.close();
    for (int i = 0; i < contArchivo; i++)
    {
        cout << aspirantes[i][0] << " " << aspirantes[i][1] << " " << aspirantes[i][2] << endl;
    }

    for (int i = 0; i < contArchivo; i++)
    {
        cout << "ingrese dni: " << endl;
        cin >> dni;
        int posiciondniencontrado = busquedaDni(aspirantes,dni,contArchivo);
        for (int j = 0; j < 4; j++)
        {
            cout << "ingrese codigo de prueba : " << endl;
            cin >> codPrueba;
            cout << "ingrese nota :" << endl;
            cin >> nota;
            postulantes[posiciondniencontrado][codPrueba - 1] += nota;
        }
    }
    calc_punt(postulantes, contArchivo);
        //informe A
    for (int i = 0; i < contArchivo; i++)
    {
        cout<<aspirantes[i][0]<<"   "<<postulantes[i][1]<< "   "<<postulantes[i][2]<<"    ";
        cout<<postulantes[i][3]<<"   "<<postulantes[i][4]<<"  "<<postulantes[i][0]<<endl; 
    }
    //informe B 
    float suma = 0;
    float promedio;
    float maximo = 0;
    float minimo = 999;
    for (int i = 0; i < contArchivo; i++)
    {
        if (postulantes[i][0]>maximo){
            maximo = postulantes[i][0];
        }
        if (postulantes[i][0]<minimo){
            minimo = postulantes[i][0];
        }
        {
            /* code */
        }
        
        suma = suma + postulantes[i][0];
    }
    promedio = suma/contArchivo;
    cout<<"El promedio es :"<<promedio<<endl;
    cout<<"El valor minimo es : "<<minimo<<endl;
    cout<<"El valor maximo es :"<<maximo<<endl;

    ofstream archivo2;
    archivo2.open("./puntajessuperiores");
    if (archivo2.fail())
    {
        cout<<"ERRRORRRRRRRR"<<endl;
    }
    for (int i = 0; i < contArchivo; i++)
    {
        if (postulantes[i][0]>= promedio)
        {
            archivo2<<aspirantes[i][0]<<endl<<nya_aspirantes[i]<<endl<<aspirantes[i][1]<<endl<<postulantes[i][0]<<endl;
        }
        
    }
    


    return 0;
}


void calc_punt(long postulantes[][5],int contArchivo){
    for (int i = 0; i < contArchivo; i++)
    {
        postulantes[i][0] = (postulantes[i][1]*2) + (postulantes[i][2]*3) + (postulantes[i][3]*4) + (postulantes[i][4]*5);
    }
    

}

int busquedaDni(long aspirantes[][2],int dni, int contArchivo){
    int pos,band=0;
   for (int i = 0; i < contArchivo; i++)
   {
    if (dni == aspirantes[i][0])
    {
        i=contArchivo;
        pos=i;
        band=1;
    }
    

   }
   if (band == 1)
   {
    return pos;
   } else {
    return 0;
   }


}