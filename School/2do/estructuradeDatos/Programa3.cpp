#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


void lectura(int [], int);
void impresion(int [], int [], int);
double promedio(int [], int);
int  NumMayor(int [], int);
int NumMenor(int [], int);
bool busqueda(int [], int);

int main(){
    int stat[5] = { 1, 2, 4, 6, 8};

    int n, *dina;
    cout << "Ingrese el numero de datos: ";
    cin >> n;
    dina = new int[n];

    cout << "Lectura de datos: \n";
    lectura(dina, n);

    cout << "Impresion de datos: \n";
    impresion(dina , stat, n);

    cout << "\n Promedio de datos \n";
    double prom = promedio(dina, n);
    printf("El promedio es: %f \n", prom);

    int mayor = NumMayor(dina, n);
    printf("\nEl numero mayor es: %d \n", mayor);

    int menor = NumMenor(dina, n);
    printf("\nEl numero menor es: %d \n", menor);
    
    
    bool busq = busqueda(dina, n);
    if(busq == true){
        printf("TRUE \n");
    }else{
        printf("FALSE \n");
    }
}


//Fuciones


void lectura(int dina[], int n){
    for(int i = 0; i < n; i++){
        cin >> dina[i];
    }
}
void impresion(int dina[], int stat[], int  n){
    for(int i = 0; i < 5; i++){
        printf("%d ", stat[i]);
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        printf("%d ", dina[i]);
    }
    cout << "\n";
}
double promedio(int dina[], int n){
    double promediod = 0.0;
    for(int i = 0; i < n; i++){
        promediod += dina[i];
    }

    return promediod / n;
}
int NumMayor(int dina[], int n){
    int mayor = 0;

    for(int i = 0; i < n; i++){
        if(dina[i] > mayor){
            mayor = dina[i];
        }
    }

    return mayor;
}

int NumMenor(int dina[], int n){
    int menor = 1000000000;

    for(int i = 0; i < n; i++){
        if(dina[i] < menor){
            menor = dina[i];
        }
    }

    return menor;
}
bool busqueda(int dina[], int n){
    int busqueda = false;
    cin >> busqueda;
    for(int i = 0; i < n; i++){
        if(busqueda == dina[i]){
            return true;
        }else 
            return false;
    }
}