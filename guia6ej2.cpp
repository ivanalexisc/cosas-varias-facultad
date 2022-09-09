/*Se dispone de una lista con los 25 números de documentos de un grupo de alumnos, guardados en
un vector DNI. Además, por cada alumno se tiene las 3 calificaciones obtenidas en los exámenes
parciales de una materia, las cuales se almacenan en una matriz llamada NOTA. Se desea conocer el
promedio de un alumno del que se lee su número de documento como dato. Si el número de documento
buscado no se encuentra mostrar un mensaje que indique que el mismo no fue hallado.
*/ 

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
int DNI[25], NOTA[25][3]; // NOTA[i][0 para la nota numero 1 ] || NOTA[i][1 para la nota numero 2 ] || NOTA[i][2 para la nota numero 3 ]
int i, band=0, dat, pos;
const int cant = 3;
for (int i = 0; i <cant; i++)
{
    cout<<"ingrese el dni del alumno"<<endl;
    cin>>DNI[i];
}
for (int i=0; i <cant; i++)
{
   cout<<"Ingrese la nota del parcial n° 1 : "<<endl;
   cin>>NOTA[i][0];
   cout<<"Ingrese la nota del parcial n° 2 : "<<endl;
   cin>>NOTA[i][1];
   cout<<"Ingrese la nota del parcial n° 3 : "<<endl;
   cin>>NOTA[i][2];

}

 



cout<<"*****************************************"<<endl;
cout<<"Ingrese el dato a buscar: ";
cin>>dat;
i=0; 
while (i < cant){
    if (DNI[i] == dat){
        band=1;
        pos=i;
        i=cant;
    }
    i++;
}
cout<<"*****************************************"<<endl;

if (band == 0){
    cout<<"El dato no fue hallado";
}else{ cout<<"El dni fue hallado en la posicion "<<pos<<"Y el promedio es : "<<endl<<((NOTA[pos][0]+NOTA[pos][1]+NOTA[pos][2])/3.0);
};





    return 0;
}



