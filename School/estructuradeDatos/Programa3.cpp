#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


void lectura(int stat[], int dina[]);
void impresion(int stat[], int dina[]);
double promedio(int stat[], int dina[]);
int  NumMayor(int stat[], int dina[]);
int NumMenor(int stat[], int dina[]);
bool busqueda(int stat[], int dina[]);

int main(){
    int stat[5] = { 1, 2, 4, 6, 8};
    int dina[5];

    for(auto i = 0; i < 5; i++){
        cin >> dina[i];
    }

    lectura(dina, stat);
    impresion(dina , stat);
    double prom = promedio(dina, stat);
    printf("El promedio es: %f \n", prom);
    int mayor = NumMayor(dina, stat);
    printf("El numero mayor es: %d \n", mayor);
    int menor = NumMenor(dina, stat);
    printf("El numero menor es: %d \n", menor);
    
    
    bool busq = busqueda(dina, stat);
    if(busq){
        printf("TRUE \n");
    }else{
        printf("FALSE \n");
    }
}
void lectura(int dina[5], int stat[5]){
    int lects[5];
    int lectd[5];

    for(auto i = 0; i < 5; i++){
        lectd[i] = dina[i];
        lects[i] = stat[i];
    }
}
void impresion(int dina[], int stat[]){
    for(auto i = 0; i < 5; i++){
        printf("%d ", stat[i]);
    }
    cout << "\n";
    for(auto i = 0; i < 5; i++){
        printf("%d ", dina[i]);
    }
    cout << "\n";
}
double promedio(int dina[], int stat[]){
    double promediod = 0.0;
    for(auto i = 0; i < 5; i++){
        promediod += dina[i];
    }

    return promediod / 5;
}
int NumMayor(int dina[], int stat[]){
    int mayor = 0;

    for(auto i = 0; i < 5; i++){
        if(dina[i] > mayor){
            mayor = dina[i];
        }
    }

    return mayor;
}

int NumMenor(int dina[], int stat[]){
    int menor = 1000000000;

    for(auto i = 0; i < 5; i++){
        if(dina[i] < menor){
            menor = dina[i];
        }
    }

    return menor;
}
bool busqueda(int dina[], int stat[]){
    int busqueda;
    cin >> busqueda;
    for(auto i = 0; i < 5; i++){
        if(busqueda == dina[i]){
            return true;
        }
    }
}