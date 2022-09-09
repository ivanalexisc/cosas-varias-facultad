#include <iostream>
using namespace std;
int main (){
int mat[10][6];
for (int i = 0; i <10; i++)
for(int j = 0; j<6; j++)
{
    cout<<"Dato de fila"<<i<<"Columna"<<j<<":";
    cin>> mat[i][j];
}



    return 0;
}