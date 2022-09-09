/*  11) Una empresa textil, dedicada al hilado de lana ovina, recibe su materia prima de distintos criaderos
de ovejas distribuidos en el país.
Mensualmente, se ingresan sin orden alguno, los siguientes datos de los N criaderos de oveja: Nro de
criadero (de 1 a N), tipo de oveja (1: Merino, 2: Texel, 3: Dorset), cantidad de kilos lana. Se sabe que
puede venir más de una entrada de lana, para un mismo criadero y un mismo tipo de oveja. También
puede ser que algún criadero no haya enviado alguno de los tipos de lana. El fin de datos está dado por
Nro de criadero = 999.
El valor N se ingresa como primer dato.
Se desea:
a) Emitir un listado ordenado en forma decreciente, por costo a abonar a cada criadero, sabiendo que el
kilo de lana se abona a razón de $800, independientemente del tipo de lana. El formato es el siguiente:
 Nro. Criadero Costo total ($)
 xxxxxx xxxx
b) Dado un tipo de lana (1, 2 ó 3) que se ingresa como dato, buscar entre los criaderos, si al menos uno
de ellos no ha enviado ese tipo de lana (valor 0). Informar con las siguientes leyendas alusivas según el
caso: “TODOS ENVIARON” ó “NO TODOS ENVIARON”. */


 #include <iostream>
 #include <cmath>
 #include <string.h>
 using namespace std;
 
 
 int main(int argc, char const *argv[])
 {
   int nroCriadero;
   int n, tipoOveja,cantKilos,tipo,band=0;
   int criaderos[n][5]; // criaderos[n][0 para kilos lana ] criaderos[n]||[1 para tipo de lana 1 ] criaderos[n][2 para tipo de lana 2 ]||criaderos[n][3 para tipo de lana 3] criaderos[n][4 para nro de criadero] 
   int criaderosAux[n][5];
   
   
   cout<<"Ingrese N : "<<endl;
   cin>>n;

      for (int i =0; i < n; i++)
         {
            for (int j = 0; j <4; j++)
               {
                  criaderos[i][j] = 0;
                  }
   
         }

 cout<<"Ingrese el numero de criadero"<<endl;
 cin>>nroCriadero;
 
   while (nroCriadero!=999)
   {
      criaderos[n][4] = nroCriadero;
      cout<<"Ingrese tipo de oveja  (1: Merino, 2: Texel, 3: Dorset) : "<<endl;
      cin>>tipoOveja;
      cout<<"Ingrese la cantidad de kilos lana"<<endl;
      cin>>cantKilos;
     // sumo la cantidad por criadero 
      criaderos[nroCriadero][tipoOveja] = criaderos[nroCriadero][tipoOveja] + cantKilos;
   // sumo el total de todos los criaderos
      criaderos[nroCriadero][tipoOveja] = criaderos[nroCriadero][0] + cantKilos;

       cout<<"Ingrese el numero de criadero"<<endl;
         cin>>nroCriadero;
   }
 //a) ordeno por mayor y 

 for (int i=0; i < (n-1); i++){
   for (int j=i+1; j<n; j++){
      if (criaderos[i][0] < criaderos[j][0]){
         criaderosAux[i][0] = criaderos[i][0];
         criaderosAux[i][1] = criaderos[i][1];
         criaderosAux[i][2] = criaderos[i][2];
         criaderosAux[i][3] = criaderos[i][3];
         criaderosAux[i][4] = criaderos[i][4];
 
         criaderos[i][0] = criaderos[j][0];
         criaderos[i][1] = criaderos[j][1];
         criaderos[i][2] = criaderos[j][2];
         criaderos[i][3] = criaderos[j][3];
         criaderos[i][4] = criaderos[j][4];
 
         criaderos[j][0] = criaderosAux[i][0];
         criaderos[j][1] = criaderosAux[i][1];
         criaderos[j][2] = criaderosAux[i][2];
         criaderos[j][3] = criaderosAux[i][3];
         criaderos[j][4] = criaderosAux[i][4];
      }
   }
 }

 
 
 for (int i = 0; i <n; i++)
 {
   cout<<"Nro de criadero"<<criaderos[i][4]<<endl<<"Costo total: "<<endl<<criaderos[i][0]*800<<endl;
 }


 //b) ingreso el tipo de lana y muestro si enviaron o no enviaron

 cout<<"ingresar el tipo de lana 1 2 o 3 "<<endl;
 cin>>tipo;

for (int i = 0; i <n; i++)
   {
      if(criaderos[i][tipo] == 0){
         band= 1;
      }

   }  

   if(band == 1){
      cout<<"no todos enviaron"<<endl;
   } else 
   {
      cout<<"Todos enviaron"<<endl;
   }
 
 
 
 
    return 0;
 }