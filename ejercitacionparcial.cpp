/*Una empresa de envíos posee una App para que los clientes realicen pedidos y desea realizar el control de los
pedidos que procesa. La empresa cuenta con 4 tipos de delivery: 1: supermercados, 2: kioscos, 3: rotiserías y
4: farmacias (codificados de 1 a 4). Posee un archivo llamado “unidades.txt” que contiene los comercios
adheridos a cada tipo de delivery. Cada registro del mismo, tiene los siguientes campos: tipo de delivery (1 a 4),
código de unidad (ej: S1, K2, etc), nombre comercio, dirección y ciudad.
Por otro lado, la empresa emplea repartidores a los cuales se les asignan las órdenes del día, y dispone de un
archivo llamado “repartidores.txt” con la siguiente información en cada registro y por cada repartidor: dni,
nombre y apellido, estado (D: disponible o ND: no disponible), puntuación y ciudad.
Por cada envío se ingresan los siguientes datos: código unidad, nombre de la persona que realiza el pedido,
ciudad y teléfono de contacto. Estos datos se ingresan sin orden. Un código de unidad z0 99 determina el fin de
la carga de datos.
A medida que se ingresan los pedidos, se debe verificar si existe disponibilidad de repartidores en dicha ciudad
para cumplir con la orden solicitada. En caso que haya disponible más de un repartidor, se escoge al de mayor
puntuación y, de ese manera, se genera la adjudicación del envío y se debe actualizar el estado de dicho
repartidor. Caso contrario, ese pedido queda como pendiente.
Se desea:
1) Crear una función comprobar_repartidor, que verifique si es posible o no cumplir con la solicitud.
2) Generar un informe de todos los tipos de delivery que han tenido movimiento.
Tipo de delivery Cant. total pedidos Cant. total pedidos asignados
1 xxx xxx
2 xxx xxx
3 xxx xxx
4 xxx xxx*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;
bool comprobar_repartidor(string repartidores[][5],int contRepartidores, string ciudad);
int busquedaDevuelveTipoDeli(string unidades[][4],int tam,string codUnidad,int tipoDelivery[100]);
int main(int argc, char const *argv[])
{
    int tipoDelivery[100],telefono,pedidos[4][2];
    string unidades[100][4], codUnidad;
    string repartidores[100][5],nombrePersona,ciudad;
    ifstream archivo1, archivo2;

    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <2; j++)
        {
            pedidos[i][j]=0;
        }
        
    }
    

    archivo1.open("./unidades.txt");
    if (archivo1.fail())
    {
        cout << "error" << endl;
    }

    int c = 0;

    archivo1 >> tipoDelivery[c];
    while (!archivo1.eof())
    {
        archivo1.ignore();
        getline(archivo1, unidades[c][0]);
        archivo1.ignore();
        getline(archivo1, unidades[c][1]);
        getline(archivo1, unidades[c][2]);
        getline(archivo1, unidades[c][3]);
        c++;
        archivo1 >> tipoDelivery[c];
    }
    archivo1.close();

    for (int i = 0; i < c; i++)
    {
        cout << tipoDelivery[i] << " " << unidades[i][0] << " " << unidades[i][1] << " " << unidades[i][2] << " " << unidades[i][3] << endl;
    }

    archivo2.open("./repartidores.txt");
    if (archivo2.fail())
    {
        cout << "error" << endl;
    }
    int contRepartidores = 0;
    archivo2 >> repartidores[contRepartidores][0];
    while (!archivo2.eof())
    {
        archivo2.ignore();
        getline(archivo2, repartidores[contRepartidores][1]);
        getline(archivo2, repartidores[contRepartidores][2]);
        getline(archivo2, repartidores[contRepartidores][3]);
        getline(archivo2, repartidores[contRepartidores][4]);
        contRepartidores++;
        archivo2 >> repartidores[contRepartidores][0];
    }

    archivo2.close();

    for (int i = 0; i < contRepartidores; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << repartidores[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Ingrese codigo de unidad :" << endl;
    cin>>codUnidad;
    while (codUnidad != "99")
    {
       cin.ignore();
        cout << "ingrese el nombre de la persona : " << endl;
        getline(cin, nombrePersona);
        cout << "Ingrese la ciudad : " << endl;
        getline(cin, ciudad);
        cout << "telefono de contacto" << endl;
        cin>>telefono;
        comprobar_repartidor(repartidores, contRepartidores,ciudad);
       int tipo = busquedaDevuelveTipoDeli(unidades,100,codUnidad,tipoDelivery);
        if (comprobar_repartidor(repartidores,contRepartidores,ciudad))
        {
            cout << "se encontró repartidor" << endl;
            pedidos[tipo-1][1]++;
        } else{
            cout<<"no se encontro repartidor"<<endl;
           
        }
         pedidos[tipo-1][0]++;
        cout << "Ingrese codigo de unidad :" << endl;
        cin>>codUnidad;
        
    }
    cout<<"cant total de pedidos : "<< " "<< "cant total de pedidos asignados : "<<endl;
    for (int i = 0; i <4; i++)
    {
        
        
        cout<<pedidos[i][0]<<" "<<pedidos[i][1]<<endl;
    }
    


    return 0;
}

bool comprobar_repartidor(string repartidores[][5],int contRepartidores, string ciudad){

for (int i = 0; i < contRepartidores; i++)
{
    if (repartidores[i][2] == "D" && ciudad == repartidores[i][4])
    {
        return true;
    } 
    
}  
        return false;
    

}

int busquedaDevuelveTipoDeli(string unidades[][4],int tam,string codUnidad,int tipoDelivery[100]){
    int band=0, pos;

    int i = 0; 
    while (i < tam){
        if (unidades[i][0] == codUnidad){
            band=1;
            pos=i;
            i=tam;
        }
        i++;
    }
    if (band == 0){
    return 0;
    }else{ return tipoDelivery[pos];
    }
}