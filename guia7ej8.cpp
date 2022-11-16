/*8. En distintas localidades de Buenos Aires, Entre Ríos y Tucumán se realiza el cultivo de
arándanos. Se necesitan hacer algunos cálculos estadísticos generales de lo que sucede en
las diferentes provincias y en Entre Ríos en particular sobre el incremento de su producción.
Se ingresan los datos de las distintas localidades de las provincias de la siguiente forma:
código de la provincia (1: Buenos Aires, 2: Entre Ríos y 3:Tucumán), cantidad de localidades
que producen arándanos y luego, por cada una de esas localidades: código de localidad
(1..N), superficie cosechada (en ha) y producción en toneladas en el año .
Luego, se ingresan sólo para las N localidades de Entre Ríos, lo producido en el año pasado,
de la siguiente manera: código de localidad (1..N) y producción en toneladas en el año
anterior.
Se desea calcular e informar:
a) El rendimiento en kg/ha de cada localidad.
b) El promedio de rendimiento entre las tres provincias
c) El nombre de la provincia con mejor rendimiento.
d) De las localidades de la Provincia de Entre Ríos el promedio de producción de los dos
últimos años
Diseñar una función para cada punto.
Obs.: Rendimiento (kg/ha) = producción en tn/superficie cosechada * 1000
*/


#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
float rendimiento(float kg, float ha);
float rendimiento_prov(float arreglo[][2][3], int cant_loc, int cod_prov );
float promedioRendimiento(float arreglo[][2][3],int vec_cant[]);
string mejor_rendimiento(float arreglo[][2][3], int vec_cant[], string nombres[]);
float prom_2_anios(float prod_anio1, float prod_anio2);

int main(int argc, char const *argv[])
{
float produccion[100][2][3];
float prod_ant[100];
int codProv, cantLocalidades[3]={0}, codLocalidades;
string nombres_provincias[] = {"Buenos Aires", "Entre rios", "Tucuman"};

for (int i = 0; i <100; i++){
   for (int j=0; i <2; j++)
   {
    for (int k = 0; k <3; k++)
    {
        produccion[i][j][k] = 0;
    }
    
   }
    prod_ant[100] = 0;
}

for (int x= 0; x<3; x++)
{
    cout<<"ingrese el codigo de la provincia"<<endl;
    cin>>codProv;
    cout<<"Ingrese la cantidad de localidades que producen arandanos"<<endl;
    cin>>cantLocalidades[codProv-1];

   
        for (int i = 0; i < cantLocalidades[codProv-1]; i++){
            cout<<"Ingrese codigo de localidad"<<endl;
            cin>>codLocalidades;

            cout<<"Superficie cosechada"<<endl;
            cin>>produccion[codLocalidades-1][0][codProv-1];

            cout<<"produccion en Tn";
            cin>>produccion[codLocalidades-1][1][codProv-1];

    }
}

cout<<"Carga de datos para el año anterior en er";
for (int i=0; i <cantLocalidades[1]; i++)
{
            cout<<"Ingrese codigo de localidad"<<endl;
            cin>>codLocalidades;

            cout<<"produccion en Tn";
            cin>>prod_ant[codLocalidades-1];
}

//informe A
cout<<"Rendimiento por localidad"<<endl;
for (int i=0; i <3; i++){
    cout<<nombres_provincias[1]<<endl;
    for (int j = 0; j <cantLocalidades[i]; j++)
    {
        cout<<"Localidad codigo"<<(j+1)<<rendimiento(produccion[j][1][i],produccion[j][0][i])<<endl;
    }
    
}

//informe B
cout<<"Promedio de rendimiento: "<<promedioRendimiento(produccion,cantLocalidades) <<endl;

//informe C
cout<<"Provincia con mejor rendimiento"<<mejor_rendimiento(produccion,cantLocalidades,nombres_provincias) <<endl;

//informe D
cout<<"Prom x localidad er ultimos 2 anios"<<endl;
for (int i = 0; i < cantLocalidades[1]; i++)
{
    cout<<"Localidad codigo"<<(i+1)<<prom_2_anios(produccion[i][1][1], prod_ant[i])<<endl;
}



    return 0;
}

float rendimiento(float tn, float ha){
float calculo = tn/ha*1000;
return calculo;
}


float rendimiento_prov(float arreglo[][2][3], int cant_loc, int cod_prov ){
    float acum = 0;
    for (int i = 0; i <cant_loc; i++){
        acum += rendimiento(arreglo[i][1][cod_prov-1],arreglo[i][0][cod_prov-1]);
    }
    return  acum/cant_loc;

    
}

float promedioRendimiento(float arreglo[][2][3],int vec_cant[]){
    float acum= 0;
    for (int i = 0; i <3; i++)
    {
       acum += rendimiento_prov(arreglo, vec_cant[i], (i+1) ); 
    }
    return acum/3;
    
}

string mejor_rendimiento(float arreglo[][2][3], int vec_cant[], string nombres[]){
    float max_rend = 0,aux_rend;
    int max_ind;
     for (int i = 0; i <3; i++)
    {
       aux_rend = rendimiento_prov(arreglo, vec_cant[i], (i+1) ); 

       if(max_rend < aux_rend){
        max_rend = aux_rend;
        max_ind = i;
       }
    }
    return nombres[max_ind];
}

float prom_2_anios(float prod_anio1, float prod_anio2){
    return (prod_anio1 + prod_anio2)/2;
}