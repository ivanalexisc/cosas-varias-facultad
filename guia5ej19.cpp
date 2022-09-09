

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
int n = 5,codTema;
int masDeDiezTemas = 0;
int tema[n][3]; //tema[n][0-codigo de tema] ||tema[n][1-costo del tema] || tema[n][2-cantidad de interesados]
string nombreTema[n];
int presupuestoTotal=0;

//Inicializo toda la matriz en 0
for (int i = 0; i < n; i++)
{
    for (int j = 0; j <3; j++)
    {
        tema[i][i] = 0;
    }
    
}




// temas seleccionados por la empresa
//lleno la matriz con los datos
for (int i =0; i<n; i++)
{
   
    cout << "Ingrese codigo de tema" << endl;
    cin >>tema[i][0];
    cout << "ingresar nombre del tema " << endl;
    cin.ignore();
    getline(cin,nombreTema[i]);
    cout << "Ingrese costo de capacitacion" << endl;
    cin>>tema[i][1]; 
}
    

for ( int i =0; i <5; i++)
{
    cout << "Ingrese codigo de tema" << endl;
    cin >>codTema;


    int cantidadTemasQueQuiereEstudiarEsteCliente = 0;

    while (codTema != 0)
    {
        for (int i =0; i <n; i++)
        {
            if(tema[i][0] = codTema){
                tema[i][2] = tema[i][2] + 1;
                presupuestoTotal = presupuestoTotal + tema[i][1];
            }
        }
        cantidadTemasQueQuiereEstudiarEsteCliente = cantidadTemasQueQuiereEstudiarEsteCliente +1;
        cout << "Ingrese codigo de tema" << endl;
        cin >>codTema;

    }
        //a) informo cuantos temas quiere estudiar cada cliente
    cout <<"El cliente numero : "<<i<<"Quiere estudiar"<<cantidadTemasQueQuiereEstudiarEsteCliente<<"temas."<<endl;
    if(cantidadTemasQueQuiereEstudiarEsteCliente>10){
        masDeDiezTemas=masDeDiezTemas+1;
    }
}



// informe
//b) cantidad de  interesados de cada tema
for (int i =0; i < n; i++)
{
    cout<<"Descripcion del tema : "<<nombreTema[i]<<"|| Cantidad de interesados en el tema"<<tema[i][2]<<endl;
}
// c) numero de personas que eligieron mas de 10 temas
    cout<<"La cantidad de personas que eligieron mas de 10 temas son "<<masDeDiezTemas<<endl;


//d) presupuesto total 
cout<<"El presupuesto total que se necesita es :"<<presupuestoTotal<<endl;


    return 0;
}