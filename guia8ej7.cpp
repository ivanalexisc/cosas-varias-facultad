/*7. Se desea llenar una matriz de N x M con números al azar menores a 1000. Los valores de N y M
se ingresan como primeros datos. Luego generar un archivo MATRIZ.TXT donde se guarde: N, M,
luego los valores de cada una de las celdas recorriendo la matriz por filas y columnas. Por último la
suma de todos los valores. Todos los valores se escriben separados por espacios en blanco.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
ofstream archivo;
int N,M,suma;

archivo.open("./MATRIZ.TXT");





if (archivo.fail())
{
    cout << "ERROR" << endl;
    exit(1);
}
cout<<"Ingresar N : "<<endl;
cin>>N;
cout<<"Ingrese M:"<<endl;
cin>>M;
archivo<<N<<" "<<M<<endl;
int matriz[N][M];
for (int i = 0; i <N; i++)
{
    for (int j = 0; j <M; j++)
    {
        matriz[i][j]=rand()%1000;

        archivo<<matriz[i][j]<<" ";
        suma += matriz[i][j];
        
    }
    archivo<<endl;
    
}
archivo<<suma;
archivo.close();


    return 0;
}