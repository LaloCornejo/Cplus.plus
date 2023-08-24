// Author: L Æ L Ö

#include<iostream>
#include<cstdio>
using namespace std;

struct direccion{
    string calle;
    int numero;
    string colonia;
};

struct alumno{
    string nombre;
    direccion dir;
    int calif[3];
};
int main(){
    alumno x[4];

    for(int i = 0; i < 4; i ++){
        cin >> x[i].nombre >> x[i].dir.calle >> x[i].dir.numero >> x[i].dir.colonia >> x[i].calif[0] >> x[i].calif[1] >> x[i].calif[2];
    }

    for(int j = 0; j < 4; j ++){
        cout << "\nNombre: " << x[j].nombre << "\n";
        cout << "Calle: " << x[j].dir.calle << "\n";
        cout << "Colonia: " << x[j].dir.colonia << "\n";
        printf( "Numero: %d\nCalif 1: %d\nCalif 2: %d\nCalif3: %d\n" , x[j].dir.numero, x[j].calif[0], x[j].calif[1] ,x[j].calif[2]);
    }

    return 0;
}