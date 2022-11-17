/*El gobierno desea realizar un estudio de h�bitos de consumo de alcohol y bebidas en la regi�n. Para ello, ha escogido 50 localidades con menos de
6.000 habitantes, donde llevará a cabo el estudio. Para ello dispone de un archivo llamado "ciudades.txt" que contiene por cada localidad:
c�digo (1-50) y nombre.
Tambi�n se dispone de un archivo "tipos_de_bebida.txt" con la siguiente informaci�n por rengl�n (separado por espacio en blanco):
c�digo de tipo de bebida (1-7) , tipo de bebida (0: sin alcohol, 1: bebida alcoh�lica), descripci�n de la bebida. 
En cada uno de estas localidades se relevar� el n�mero de litros consumidos durante el a�o pasado de los 7 tipos de bebidas.

Se lee y almacena la siguiente informaci�n: c�digo de localidad, c�digo de tipo de bebida , litros consumidos y grupo etario (G1: adolescentes,
G2: Adultos y G3: adultos mayores). La informaci�n no viene ordenada y puede que de alg�n tipo de bebida no se tenga informaci�n. El fin de datos
est� dado por c�digo de localidad = 0.

Se desea:
a) Determinar e informar de los "tipos de bebidas" con alcohol: �cual es el mas consumido?
Para este punto utilice una funci�n que reciba el/los arreglos de tipos de bebidas y devuelva por par�metro el nombre del tipo de bebida m�s consumido.

b) Informar totales de bebidas consumidas por grupo etario en todas las localidades, seg�n el siguiente formato
Grupo/Tipo de bebidas        1         2       3        4       5       6      7
G1                                         xx       xx      xx       xx     xx     xx    xx
G2                                         xx       xx      xx       xx     xx     xx    xx
G3                                         xx       xx      xx       xx     xx     xx    xx

c) Generar un archivo que contenga la siguiente informaci�n ordenada de manera ascendente por tipo de bebida: Código de bebida, Descripci�n y luego
la informaci�n de la localidad donde m�s se consum�a ese tipo de bebida: C�digo de Localidad, Nombre de Localidad y Cantidad total de litros consumidos.
Para este punto utilice una funci�n que devuelva en el nombre el c�digo de la localidad que m�s consum�a el codigo de bebida recibida por par�metro.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Punto A: funci�n que reciba el/los arreglos de tipos de bebidas y devuelva por par�metro el nombre del tipo de bebida m�s consumido.
string busca_mas(string desc[], int tb[], float tlit[]);
//Punto c: unci�n que devuelva en el nombre el c�digo de la localidad que m�s consum�a el codigo de bebida recibida por par�metro
void mayor_consumo(int col, int &loc, float &aux_max, float tb[][8]);

int main() {
	string nom_loc[51]; //nombre localidades
	string descr_b[8]; //descripcion bebidas
	int tipob[8]; //tipo de bebida (0: sin alcohol, 1: bebida alcoh�lica)
	float litrosb, totlitros[8]; //totlitros acumula litros por tipo de bebida
	float total_bebidas[51][8]; //acumula litros por localidad y por tipo de bebida
	float totalge[3][8];
	string mas_consumo; //auxiliar para devolver resultado de funci�n
	int i, j, codl, codb, ge, localidad;
	float max_litros;
	string grupoe;
	
	//INICIALIZAR EN 0 ARREGLOS
	for(i=0; i<8; i++)
		totlitros[i]=0;
	
	for(i=0; i<3; i++)
		for(j=0; j<8; j++)
			totalge[i][j]=0;
	
	for(i=0; i<51; i++)
		for(j=0; j<8; j++)
			total_bebidas[i][j]=0;		
	
	//EXTRAE DATOS ARCHIVO CIUDADES.TXT
	ifstream archi;
	archi.open ("./CIUDADES.TXT");
	if ( archi.fail() ) {
		cout << "Error en la apertura del archivo.";
	}
	else {	
		archi>>codl;
		while (!archi.eof())
		{
			archi.ignore();
			getline(archi,nom_loc[codl]);
			archi>>codl;
			
		}
	}	
	archi.close ();
	
	//EXTRAE DATOS ARCHIVO TIPOS_DE_BEBIDA.TXT
	ifstream archi1;
	archi1.open ("./TIPOS_DE_BEBIDA.TXT");
	if ( archi1.fail() ) {
		cout << "Error en la apertura del archivo.";
	}
	else {	
		archi1>>codb;
		while (!archi1.eof())
		{
			archi1>>tipob[codb];
			archi1.ignore();
			getline(archi1,descr_b[codb]);
			archi1>>codb;			
		}
	}	
	archi1.close ();
	
	/*Se lee y almacena la siguiente informaci�n: c�digo de localidad, c�digo de tipo de bebida , litros consumidos y grupo etario (G1: adolescentes,
	G2: Adultos y G3: adultos mayores). La informaci�n no viene ordenada y puede que de alg�n tipo de bebida no se tenga informaci�n. El fin de datos
	est� dado por c�digo de localidad = 0.*/
	
	cout<<"COD. LOCALIDAD: ";
	cin>>codl;
	while(codl != 0)
	{
		cout<<"COD. BEBIDA: ";
		cin>>codb;
		cout<<"LITROS CONSUMIDOS: ";
		cin>>litrosb;
		cin.get();
		cout<<"GRUPO ETARIO (G1, G2 o G3): ";
		getline(cin, grupoe);
		if(grupoe=="G1")
			ge=0;
		else if(grupoe=="G2")
			ge=1;
		else ge=2;
		
		totlitros[codb]=totlitros[codb] + litrosb;
		totalge[ge][codb]=totalge[ge][codb] + litrosb;
		total_bebidas[codl][codb]= total_bebidas[codl][codb] + litrosb;
		
		cout<<"COD. LOCALIDAD: ";
		cin>>codl;		
	}
	
	/*) Determinar e informar de los "tipos de bebidas" con alcohol: �cual es el mas consumido?
	Punto A: funci�n que reciba el/los arreglos de tipos de bebidas y devuelva por par�metro el nombre del tipo de bebida m�s consumido.*/
	mas_consumo=busca_mas(descr_b, tipob, totlitros);
	cout<<endl<<"La bebida alcoholica mas consumida es: "<<mas_consumo<<endl<<endl;
	
	/*b) Informar totales de bebidas consumidas por grupo etario en todas las localidades, seg�n el siguiente formato
	Grupo/Tipo de bebidas        1         2       3        4       5       6      7*/
	cout<<endl<<"Grupo/Tipo de bebidas        1         2       3        4       5       6      7"<<endl;
	for(i=0; i<3; i++)
	{
		cout<<" G"<<i+1<<"   ";
		for(j=1; j<8; j++)
			cout<<totalge[i][j]<<"   ";
		cout<<endl;
	}
	
	/*c) Generar un archivo que contenga la siguiente informaci�n ordenada de manera ascendente por Codigo de bebida: Código de bebida, Descripci�n y luego
	la informaci�n de la localidad donde m�s se consum�a ese tipo de bebida: C�digo de Localidad, Nombre de Localidad y Cantidad total de litros consumidos.
	Para este punto utilice una funci�n que devuelva en el nombre el c�digo de la localidad que m�s consum�a el tipo de bebida recibida por par�metro.*/
	
	ofstream archi2;
	archi2.open ("./NUEVO.TXT");
	if ( archi2.fail() ) {
		cout << "Error en la apertura del archivo.";
	}
	else {	
		for(j=1; j<8; j++)
		{
			localidad=0; max_litros=0;
			mayor_consumo(j, localidad, max_litros, total_bebidas);
			archi2<<j<<" "<<descr_b[j]<<" "<<localidad<<" "<<nom_loc[localidad]<<" "<<max_litros<<endl;
		}
	}	
	archi2.close ();
	return 0;
}
string busca_mas(string desc[], int tb[], float tlit[])
{
	string auxi;
	float max=0;
	int f;
	
	for(f=1; f<8; f++)
	{
		if(tb[f]==1)
			if(tlit[f]>max)
		{
			max=tlit[f];
			auxi=desc[f];
		}
			
	}
	return auxi;
}

void mayor_consumo(int col, int &loc, float &aux_max, float tb[][8])
{
	int c;
	
	for(c=1; c<51; c++)
	{
		if(tb[c][col]>aux_max)
		{
			aux_max= tb[c][col];
			loc= c;
		}
	}
	
}
