/*16. En un censo agropecuario se ha obtenido información sobre la producción agrícola de distintos
productores.
Entre otros datos se han registrado los siguientes: Código de productor, Cantidad de hectáreas
sembradas en un año, Total de Toneladas cosechadas en un año.
La cantidad de productores censados se lee como primer dato.
Genere un archivo “CENSO.TXT” con la información ingresada, La información de cada productor se
guarda en un mismo renglón, separada por espacios.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ofstream archivo;
int productores,cantHectareas,cantToneladas;
archivo.open("./CENSTO.TXT");
if (archivo.fail())
{
    cout << "ERROR!!!!!" << endl;
}
cout << "ingrese la cantidad de productores : " << endl;
cin>>productores;

for (int i = 0; i <productores; i++)
{
    cout << "codigo de productor :"  <<i+1<< endl;
    cout << "Ingrese cantidad de hectareas sembradas en un año" << endl;
    cin>>cantHectareas;
    cout << "Ingrese cantidad de toneladas sembradas en un año" << endl;
    cin>>cantToneladas;
    archivo<<i+1<<" "<<cantHectareas<<" "<<cantToneladas<<endl;

}



archivo.close();
    return 0;
}