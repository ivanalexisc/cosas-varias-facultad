/*Una cooperadora desea obtener la nómina de personas que han adquirido un bono
contribución, numerados del 1 al 100. Para ello se ingresan los nombres de cada una de las
100 personas que compraron dicho bono, ordenados por número de bono. Se quiere mostrar
al finalizar la carga, un listado con el siguiente formato:
NRO BONO PERSONA QUE ADQUIRIÓ EL BONO
1 XXXXXXXXXXXXXXXXX
2 XXXXXXXXXXXXXXXXX;
*/

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;


int main()
{
string nombre[100];
for ( int i=0; i <3; i++) //Está hecho hasta el 3 para no tener que cargar 100 nombres
{
    cout<<"Ingrese el nombre del bono";
    cin>>nombre[i];
}
cout<<"Nro de Bono:";
cout<<"Persona que adquirio el bono: "<<endl;

for (int i =0; i <100; i++)
{
    cout<<i+1;
    cout<<nombre[i]<<endl;
}





    return 0;
}