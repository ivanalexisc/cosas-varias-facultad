
/*Escribir un programa que lea una matriz de 3 filas y 3 columnas de valores enteros. A
continuación, el programa debe pedir el número de una fila. El programa deberá mostrar por
pantalla, sólo los valores de esa fila.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
int mat[3][3],fila;
for (int i=0; i <3; i++){
for (int j=0; j<3; j++){
    cout<<endl<<"Ingrese el valor de la posicion"<<i<<j<<endl;
    cin>>mat[i][j];
}

}
cout<<"Ingrese la fila que quiere visualizar"<<endl;
cin>>fila;
cout<<endl;
for(int i = 0; i<3; i++){
    cout<<mat[fila][i];
}




	return 0;
}



