#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{

int A[10], i, band=0, dat, pos, n=5;


for (i=0; i<n; i++){
    cout<<" dato "; cin>>A[i];
}
cout<<"*****************************************"<<endl;
cout<<"Ingrese el dato a buscar: ";
cin>>dat;
i=0; 
while (i < n){
    if (A[i] == dat){
        band=1;
        pos=i+1;
        i=n;
    }
    i++;
}
cout<<"*****************************************"<<endl;

if (band == 0){
    cout<<"El dato no fue hallado";
}else{ cout<<"El dato fue hallado en la posición "<<pos;
};


    return 0;
}