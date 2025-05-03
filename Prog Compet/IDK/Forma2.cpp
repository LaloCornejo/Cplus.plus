#include<bits/stdc++.h>

using namespace std;

int main(){
    char accion[8], rango[10], nombre[10];

    int n;
    cin >> n;

    string nombres[n];
    
    bool linea[n], linet[n];
    int lineaa=0, linett=0, j=0, s=0;


    for(int i = 0; i < n; i++){
        cin >> accion >> rango >> nombres[i];

        cout << accion << rango << nombres[i];
        if( accion == "LLEGA"){
            if(rango == "ALUMNO"){
                linea[i] = true;
                lineaa++;
                linet[i] = false;
            }
            if(rango == "TRABAJADOR"){
                linet[i] = true;
                linett++;
                linea[i] = false;
            }
        }else if(accion == "ATIENDE"){
            linet[i] = false;
            linea[i] = false;
            cout << "aaaa";
        }
    }
    for(int i = 0; i < n; i++){
        printf("linea: %d | linead: %d", linea[i], linet[i]);
    }
    for(int i = 0; i < n; i++){
        cout << nombres[i] << "\n";
    }
}