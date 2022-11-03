/*13. Se desea a partir de los archivos NATACION.TXT, CARRETA.TXT y BICICLETA.TXT obtener el
código del participante ganador del triatlón (participante que realizó menor tiempo).
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ifstream natacion;
ifstream carrera;
ifstream bicicleta;
int competidoresMatriz[100][2]; //0 para codigo 1 para tiempo
int competidor = 0,codigo,tiempo,codMenorTiempo;
int menor= 9999;
natacion.open("NATACION.TXT");
carrera.open("CARRERA.TXT");
bicicleta.open("BICICLETA.TXT");
for (int i = 0; i <100; i++)
{
    for (int j = 0; j < 2; j++)
    {
        competidoresMatriz[i][j] = 0;
    }
    
}



if (natacion.fail() && carrera.fail() && bicicleta.fail())
{
    cout << "ERROR!!!!!" << endl;
    exit(1);
}

while (!natacion.eof())
{
   natacion>>codigo;
   natacion>>tiempo;
   competidoresMatriz[competidor][0] = codigo;
   competidoresMatriz[competidor][1] +=tiempo;
   competidor++; 
}
competidor = 0;
while (!carrera.eof())
{
   carrera>>codigo;
   carrera>>tiempo;
   competidoresMatriz[competidor][0] = codigo;
   competidoresMatriz[competidor][1] +=tiempo;
   competidor++; 
}
competidor = 0;
while (!bicicleta.eof())
{
   bicicleta>>codigo;
   bicicleta>>tiempo;
   competidoresMatriz[competidor][0] = codigo;
   competidoresMatriz[competidor][1] +=tiempo;
   competidor++; 
}

for (int i = 0; i <competidor; i++)
{
    if (competidoresMatriz[i][1]<menor)
    {
        menor = competidoresMatriz[i][1];
        codMenorTiempo = competidoresMatriz[i][0];

    }
    
}
cout << "Ganador del triatlon codigo : " <<codMenorTiempo<<"Tiempo : "<<menor<< endl;



natacion.close();
carrera.close();
bicicleta.close();

    return 0;
}