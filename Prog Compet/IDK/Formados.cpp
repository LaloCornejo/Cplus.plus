#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    char nombre[n][10];
    bool linea[n], linet[n];

    string accion, rango;

    for(int i = 0, a = 0, t = 0, at = 0; i < n; i++){
        cin.ignore(100, '\n');
        cin >> accion;
        cout << accion;

        if( accion == "LLEGA" ){
            cin >> rango;
            cout << rango;

            if( rango == "ALUMNO"){
                linea[i] = true;
                linet[i] = false;
                cout << "N: " << i;
                cin.getline(nombre[i], 10);

            }else if( rango == "TRABAJADOR"){
                linet[i] = true;
                linea[i] = false;
                cout << "N: " << i;
                cin.getline(nombre[i], 10);

            }

        }else if( accion == "ATIENDE"){
            at++;
            linet[i] = false;
            linea[i] = false;

            while(t < at){
                if(linet[t] == true)
                    cout << nombre[t];
                t++;
                break;      
            }while(a < at){
                if(linea[a] == true)
                    cout << nombre[a];
                a++;
            }at = 0;
        }else
            break;      
    }
    
    for(int i = 0; i < n; i++){
        cout << "\nlinea: " <<  linea[i];
        cout << " linet: " << linet[i] << "\n";
    }

    return 0;
}