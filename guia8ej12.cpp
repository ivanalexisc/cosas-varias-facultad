/*12. En un triatlón participaron N competidores y por cada uno de ellos se tienen: el número de
competidor y los 3 pares de datos con la siguiente información:
 Código de Deporte (1= natación, 2=carrera, 3=bicicleta)
 Tiempo que hizo en ese deporte (en minutos)
Los pares de datos no vienen ordenados por código de deporte.
La cantidad N de participantes se ingresa como primer dato.
Se desea generar 3 archivos: NATACION.TXT, CARRETA.TXT y BICICLETA.TXT. Los archivos
tienen la misma estructura: Cod de competidor (0..N-1), espacio en blanco y Tiempo (en minutos).
Nota: Todos los competidores completaron las 3 pruebas.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ofstream natacion;
ofstream carrera;
ofstream bicicleta;
int participantes,codigoDeporte,tiempo;
natacion.open("NATACION.TXT");
carrera.open("CARRERA.TXT");
bicicleta.open("BICICLETA.TXT");
if (natacion.fail() && carrera.fail() && bicicleta.fail())
{
    cout << "ERROR" << endl;
}
cout << "Ingrese la cantidad de participantes: " << endl;
cin>>participantes;
int anotados = 0;

    while (anotados != participantes)
    {
      for (int i = 0; i <3; i++)
      {
        cout << "Ingrese el codigo del deporte" << endl;
        cin>>codigoDeporte;
        cout<<"Ingrese el tiempo en minutos:"<<endl;
        cin>>tiempo;
            switch (codigoDeporte){
                case 1:
                    natacion<<anotados<<" "<<tiempo<<endl;
                break;
                case 2:
                    carrera<<anotados<<" "<<tiempo<<endl;
                break;
                case 3:
                    bicicleta<<anotados<<" "<<tiempo<<endl;
                break;
    
   
    }
      }
      anotados++;
        
    }
    
    
    



natacion.close();
carrera.close();
bicicleta.close();

    return 0;
}