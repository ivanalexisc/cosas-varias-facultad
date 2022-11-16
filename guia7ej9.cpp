/*9. Una fábrica de calzado recibe pedidos de distribuidores, codificados de 1 a 10, sobre tres
modelos de calzado de dama A, B y C que se encuentran en oferta. Al principio se ingresa el
precio unitario de cada modelo.
Luego, por cada pedido se ingresa: código de distribuidor (1..10), el modelo (A, B, C), y la
cantidad pedida. Tener en cuenta que puede ser que haya más de un pedido por distribuidor y
que los pedidos están ordenados por distribuidor. Un nro de distribuidor = 999 indica el fin de
datos.
a) Se desea informar por cada distribuidor según el siguiente formato:
Nro de Distribuidor : xx
Modelo Cantidad pedida Monto
A xxxxxx xxxxxxx
B xxxxxx xxxxxxx
C xxxxxx xxxxxxx
b) Indicar el nombre del modelo más vendido por cada distribuidor. Para este cálculo plantear
una función.*/

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
void modeloMasVendido(float arreglo[][3]);

int main(int argc, char const *argv[])
{

float pedidosDistribuidores[10][3];
int nroDistribuidor,precioA,precioB,precioC,cantPedida;
char modelo;

for (int i =0; i<10; i++)
{
    for (int j = 0; j <3; j++)
    {
        pedidosDistribuidores[i][j] = 0;
    }
    
}
cout<<"Ingrese el precio A"<<endl;
cin>>precioA;
cout<<"Ingrese el precio B"<<endl;
cin>>precioB;
cout<<"Ingrese el precio C"<<endl;
cin>>precioC;

cout<<"Ingrese codigo de distribuidor"<<endl;
cin>>nroDistribuidor;

while (nroDistribuidor != 999)
{
   cout<<"Ingresar modelo"<<endl;
   cin>>modelo; 
   cout<<"Ingresar la cantidad pedida"<<endl;
   cin>>cantPedida;
   switch (modelo){
   case 'a':
    pedidosDistribuidores[nroDistribuidor-1][0] += cantPedida;
    break;
    case 'b':
    pedidosDistribuidores[nroDistribuidor-1][1] += cantPedida;
    break;
    case 'c':
    pedidosDistribuidores[nroDistribuidor-1][2] += cantPedida;
    break;
   }
    cout<<"Ingrese codigo de distribuidor"<<endl;
    cin>>nroDistribuidor;

}
for (int i = 0; i <10; i++)
{
    cout<<"Nro de distribuidor:"<<i+1<<endl;
    cout<<"Cantidad del modelo A:"<<pedidosDistribuidores[i][0]<<"Monto:"<<pedidosDistribuidores[i][0] * precioA<<endl;
    cout<<"Cantidad del modelo B:"<<pedidosDistribuidores[i][1]<<"Monto:"<<pedidosDistribuidores[i][2] * precioB<<endl;
    cout<<"Cantidad del modelo C:"<<pedidosDistribuidores[i][2]<<"Monto:"<<pedidosDistribuidores[i][2] * precioC<<endl;
    
}
modeloMasVendido(pedidosDistribuidores);









    return 0;
}


void modeloMasVendido(float arreglo[][3]){

for (int i = 0; i <10; i++){
    int modelo_mas_vend=0;
    int cant_mas_vend = 0;  
    for (int j = 0; j <3; j++)
    {
        if (arreglo[i][j]> cant_mas_vend)
        {
        cant_mas_vend = arreglo[i][j];
        modelo_mas_vend = j;
        }
       
    }
    if (modelo_mas_vend == 0)
    {
        cout<<"El modelo mas vendido del distribuidor nro "<<i<<"es el modelo a"<<endl; 
    } else if(modelo_mas_vend == 1){
       cout<<"El modelo mas vendido del distribuidor nro "<<i<<"es el modelo b"<<endl; 
    } else {
        cout<<"El modelo mas vendido del distribuidor nro "<<i<<"es el modelo c"<<endl; 
    }
    
    
}



}



