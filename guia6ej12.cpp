#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int matvino[500][4], auxcod, auxmov, auxcan, cantven=0;
    float precios[500], totrec = 0;
    const int cant = 3;
    int aux;

    for(int i=0; i<cant; i++){
        precios[i] = 0;
        for(int j=0; j<4; j++){
            matvino[i][j] = 0;
        }
    }

    for(int i=0; i<cant; i++){
        cout << "ingrese cod de vino: " << endl;
        cin >> auxcod;
        matvino[auxcod-1][0] = auxcod;
        cout << "precio x botella: " << endl;
        cin >> precios[auxcod-1];
        cout << "cant botellas: " << endl;
        cin >> matvino[auxcod-1][1];
    }

    cout << endl << "carga de operaciones: " << endl;
    cout << "ingrese codigo de vino:";
    cin >> auxcod;
    while(auxcod != 9999){
        cout << "tipo movimiento (1: vta 2: com):";
        cin >> auxmov;
        cout << "cant botellas: ";
        cin >> auxcan;

        //proceso de busqueda si no esta la matriz ordenada
        //con el resultado de la busqueda reemplazan auxcod-1

        if(auxmov == 1){
            matvino[auxcod-1][2] += auxcan;

            cantven += auxcan;
            totrec += (auxcan) * precios[auxcod-1];

            matvino[auxcod-1][1] -= auxcan;
        }else{
            matvino[auxcod-1][3] += auxcan;

            matvino[auxcod-1][1] += auxcan;
        }

        cout << "ingrese codigo de vino:";
        cin >> auxcod;
    }
    
    //a)
    for(int i=0; i<cant; i++){
        cout << "Cod. Vino: " << matvino[i][0];
        cout << " Cant. Botellas Vendidas: " << matvino[i][2];
        cout << " Cantidad Botellas Compradas: " << matvino[i][3];
        cout << endl;
    }

    //b)
    cout << endl << endl;
    cout << "total botellas vendidas: " << cantven << endl;
    cout << "total recaudado: " << totrec << endl;

    //c)
    //primero ordenamos por stock => columna 2 => indice 1
    for(int i=0; i < (cant-1); i++){
        for(int j=(i+1); j<cant; j++){
            // decreciente "<"
            if(matvino[i][1] < matvino[j][1]){
                //intercambio con auxiliares
                for(int k=0; k<4; k++){
                    aux = matvino[i][k];
                    matvino[i][k] = matvino[j][k];
                    matvino[j][k] = aux;
                }

                /*
                 * si quisiera ordenar los precios
                 * en este caso especial, no es necesario
                 * auxpre = precio[i];
                 * precio[i] = precio[j];
                 * precio[j] = auxpre;
                 */
            }
        }
    }
    //fin ordenamiento

    //informar
    for(int i=0; i<cant; i++){
        cout << "Cod. Vino: " << matvino[i][0];
        cout << " Cantidad Botellas Existentes: " << matvino[i][1];
        cout << " Monto $: " << (matvino[i][1] * precios[matvino[i][0]-1]) << endl;
    }

    return 0;
}