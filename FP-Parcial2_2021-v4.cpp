#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void ProcesarFecha(string cF, int &nMes);
int BuscarInversion(string cMat[][2],int nTam, string cCod);
void Ordenar(string cMat[][2], int nT[], int nTam);

int main(int argc, char *argv[]) {
	
	ifstream sucur,port,inver;
	
	string cSucursales[10];
	int nSuc,nCantSucursales,nCantPort,nFila;
	string cPort[10][2],cCodInv,cFecha;
	int nTotalInv[10]={0};
	int nMonto;
	int nCantInvers[10][12]={0},nMes;
	sucur.open("SUCURSALES.TXT");
	if (sucur.fail()){
		cout << "Error de apertura";
	}
	else {
		nCantSucursales=0;
		sucur >> nSuc;
		while (!sucur.eof()) {
			sucur.ignore();
			getline(sucur,cSucursales[nSuc-1]);
			nCantSucursales++;
			sucur >> nSuc;
		}
	}
	sucur.close();
	/*
	for (int nI=0; nI<nCantSucursales;nI++){
		cout << nI+1 << " " << cSucursales[nI] << endl;
	};
	*/
	port.open("PORTFOLIO.TXT");
	if (port.fail()){
		cout << "Error de apertura";
	}
	else {
		nCantPort=0;
		port >> cPort[nCantPort][0];
		while (!port.eof()) {
			port.ignore();
			getline(port,cPort[nCantPort][1]);
			nCantPort++;
			port >> cPort[nCantPort][0];
		}
	}
	port.close();
	/*
	for (int nI=0; nI<nCantPort;nI++){
		cout << cPort[nI][0] << " " << cPort[nI][1] << endl;
	};
	*/
	inver.open("INVERSIONES.TXT");
	if (inver.fail()){
		cout << "Error de apertura";
	}
	else {
		inver >> nSuc;
		while(!inver.eof()){
			inver >> cCodInv;
			nFila=BuscarInversion(cPort,nCantPort,cCodInv);
			inver >> nMonto;
			nTotalInv[nFila]+=nMonto;
			inver >> cFecha;
			ProcesarFecha(cFecha,nMes);
			nCantInvers[nSuc-1][nMes-1]++;
			inver >> nSuc;
			
		}
	}
	inver.close();
	cout <<"Suc.  Ene Feb Mar Abr May Jun Jul Ago Sep Oct Nov Dic"<<endl; 
	for(int nI=0;nI<nCantSucursales;nI++){
		cout <<setw(5) << nI+1;
		for(int nJ=0;nJ<12;nJ++){
			cout << setw(4) <<nCantInvers[nI][nJ];
		}
		cout << endl;
	}
	Ordenar(cPort,nTotalInv,nCantPort);
	cout << "Cod. Inv  Descripcion                             Monto"<<endl;
	for(int nI=0; nI<nCantPort; nI++){
		cout << setw(10) <<cPort[nI][0] <<setw(40)<< cPort[nI][1] << setw(15)<<setprecision(2)<< nTotalInv[nI]<<endl;
	}
	
	return 0;
}

void ProcesarFecha(string cF, int &nM){
	string cMes;
	cMes=cF.substr(3,2);
	nM=stoi(cMes);
}

int BuscarInversion(string cMat[][2],int nTam, string cCod){
	int nF;
	for(int nI=0; nI<nTam; nI++){
		if (cMat[nI][0]==cCod){
			nF=nI;
			nI=nTam;
		}
	}
	return nF;
}

void Ordenar(string cMat[][2], int nT[], int nTam){
	string cAux;
	int nAux;
	for(int nI=0; nI<nTam-1; nI++){
		for(int nJ=nI+1;nJ<nTam;nJ++){
			if (nT[nI]<nT[nJ]){
				nAux=nT[nI];
				nT[nI]=nT[nJ];
				nT[nJ]=nAux;
				for( int nK=0; nK<2;nK++){
					cAux=cMat[nI][nK];
					cMat[nI][nK]=cMat[nJ][nK];
					cMat[nJ][nK]=cAux;
				}
			}
		}
	}
}
	
