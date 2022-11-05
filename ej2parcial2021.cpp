#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

int devolverFecha(string fecha);
int busquedaIndice(string inversionesMatriz[][2], string codigoInversion);
void ordenamiento(string inversionesMatriz[][2], long monto[], int tamaño);
int main(int argc, char const *argv[])
{
    ifstream inversiones, portfolio;
    long capitalInvertido, monto[10] = {0};
    int codSucursal;
    string codInversion, fecha, inversionesMatriz[10][2], codigoInversion, descripcion;
    int sucursales[10][12], i = 0;
    char barra;
    inversiones.open("./INVERSIONES.TXT");
    if (inversiones.fail())
    {
        cout << "ERRORRRR" << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            sucursales[i][j] = 0;
        }
    }

    portfolio.open("./PORTFOLIO.TXT");
    if (portfolio.fail())
    {
        cout << "ERRORRR" << endl;
    }
    portfolio >> codigoInversion;
    while (!portfolio.eof())
    {
        portfolio.ignore();
        getline(portfolio, descripcion);
        inversionesMatriz[i][0] = codigoInversion;
        inversionesMatriz[i][1] = descripcion;
        i++;

        portfolio >> codigoInversion;
    }

    inversiones >> codSucursal;
    while (!inversiones.eof())
    {
        inversiones >> codInversion;
        inversiones >> capitalInvertido;
        inversiones.ignore();
        getline(inversiones, fecha);
        int mes = devolverFecha(fecha);
        sucursales[codSucursal - 1][mes - 1]++;
        int busqueda = busquedaIndice(inversionesMatriz, codInversion);
        monto[busqueda - 1] += capitalInvertido;

        inversiones >> codSucursal;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 12; j++)
        {
            cout << sucursales[i][j] << " ";
        }
        cout << endl;
    }
    inversiones.close();
    ordenamiento(inversionesMatriz,monto,10);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << inversionesMatriz[i][j] << " ";
        }
        cout << monto[i] << endl;
    }
    portfolio.close();

    return 0;
}

int devolverFecha(string fecha)
{
    string fechaCambiada = fecha.substr(3, 2);
    int resultado = stoi(fechaCambiada);
    return resultado;
}

int busquedaIndice(string inversionesMatriz[][2], string codInversion)
{
    int i, band = 0, pos;

    i = 0;
    while (i < 10)
    {
        if (inversionesMatriz[i][0] == codInversion)
        {
            band = 1;
            pos = i + 1;
            i = 10;
        }
        i++;
    }
    return pos;
}

void ordenamiento(string inversionesMatriz[][2], long monto[], int tamaño)
{
    string inversionesAux;
    int montoAux;
    for (int i = 0; i < (tamaño - 1); i++)
    {
        for (int j = i + 1; j < tamaño; j++)
        {
            if (monto[i] < monto[j])
            {
                montoAux = monto[i];
                monto[i] = monto[j];
                monto[j] = montoAux;
                for (int k = 0; k < 2; k++)
                {
                    inversionesAux = inversionesMatriz[i][k];
                    inversionesMatriz[i][k] = inversionesMatriz[j][k];
                    inversionesMatriz[j][k] = inversionesAux;
                }
            }
        }
    }
}
