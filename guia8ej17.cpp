/*17. Se desea procesar la información contenida en el archivo “CENSO.TXT”.
A - Un listado ordenado de mayor a menor por cantidad de hectáreas cosechas en un año.
B - El rendimiento promedio obtenido por hectárea por cada productor
C - Generar un archivo “RENDIMIENTOS.TXT” con la información de los productores que hayan
obtenido rendimientos mayores al promedio.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ifstream archivo;
ofstream archivo2;
int codigoProductor,cantHectareas,cantToneladas,cant=0; //int productores[i][0] para codigo || int productores[i][1] para cantidad de hectareas || int productores[i][2] para cantidad de toneladas 
float auxProductores[999][3],productores[999][3],promedio,promedioGeneral,promProd;
archivo.open("./CENSTO.TXT");
archivo2.open("./RENDIMIENTOS.TXT");

for (int i = 0; i <999; i++)
{
    for (int j = 0; j <3; j++)
    {
        productores[i][j]=0;
        auxProductores[i][j] = 0;
    }
    
}


if (archivo.fail() && archivo2.fail())
{
    cout << "ERROR!!!!!!" << endl;
}
while (!archivo.eof())
{
    archivo>>codigoProductor;
    archivo>>cantHectareas;
    archivo>>cantToneladas;
    productores[cant][0] = codigoProductor;
    productores[cant][1] = cantHectareas;
    productores[cant][2] = cantToneladas;
    cant++;
}

for (int i=0; i < (cant-1); i++){
    for (int j=i+1; j<cant; j++){
        if (productores[i][1] <productores[j][1]){
            
            auxProductores[i][0] = productores[i][0];
            auxProductores[i][1] = productores[i][1];
            auxProductores[i][2] = productores[i][2];

            productores[i][0] = productores[j][0];
            productores[i][1] = productores[j][1];
            productores[i][2] = productores[j][2];

            productores[j][0] = auxProductores[i][0];
            productores[j][1] = auxProductores[i][1];
            productores[j][2] = auxProductores[i][2];
        }
       
    }
    
}
for (int i = 0; i <cant; i++)
{
    for (int j = 0; j <3; j++)
    {
         cout<< productores[i][j]<<" "; 
         promedio = productores[i][2]/productores[i][1];
         promedioGeneral +=promedio;

    }
    cout<<"Promedio: "<<promedio;
    cout<<endl;
    
}

promProd = promedioGeneral /cant;
for (int i = 0; i <cant; i++)
{
     promedio = productores[i][2]/productores[i][1];
     if (promedio>promProd)
     {
        archivo2<<productores[i][0]<<" "<<productores[i][1]<<" "<<productores[i][2]<<endl;
     }
     
}



archivo2.close();
archivo.close();
    return 0;
}