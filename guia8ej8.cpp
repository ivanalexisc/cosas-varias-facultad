/*Se desea procesar el archivo MATRIZ.TXT. Mostrar la matriz de N filas x M columnas. Verificar
que el archivo no esté modificado validando que la suma de los elementos coincida con el último
dato leído.*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>


using namespace std;


int main(int argc, char const *argv[])
{

ifstream archivo;
archivo.open("./MATRIZ.TXT");
int suma;





if (archivo.fail())
{
    cout << "ERROR" << endl;
    exit(1);
}
int N;
archivo>>N;
int M;
archivo>>M;
int matriz[N][M];

while (!archivo.eof())
{
 for (int i = 0; i <N; i++){
    for (int j = 0; j <M; j++){
       archivo>>matriz[i][j];
    }
    
    
 }
    archivo>>suma;
 
}
for (int i = 0; i <N; i++)
{
    for (int j = 0; j <M; j++)
    {
        cout<<matriz[i][j]<<" ";
    }
    cout<<endl;
}

cout<<suma<<endl;




archivo.close();


    return 0;
}