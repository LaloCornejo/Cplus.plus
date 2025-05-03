#include<iostream>
using namespace std;

void imprimir(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void intercambio(){
    int n = 5;
    int a[5] = {50, 20, 40, 80, 30};
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(a[i] > a[j]){
                int aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        }
    }
    imprimir(a, n);
}

void seleccion(){
    int n = 5;
    int a[5] = {50, 20, 40, 80, 30};
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
    imprimir(a, n);
}

void insercion(){
    int n = 5;
    int a[5] = {50, 20, 40, 80, 30};
    for(int i = 0; i < n-1; i++){
        int j = i + 1;
        int aux = a[j];
        while(j >= 0 && a[j] > aux){
            a[j] = a[j-1];
            j--;
        }
        a[j + 1] = aux;
    }
    imprimir(a, n);
}

void burbuja(){
    int n = 8;
    int a[8] = {25, 60, 45, 35, 12, 92, 85, 30};
    //int n = 5;
    //int a[5] = {50, 20, 40, 80, 30};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(a[j] > a[j+1]){
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
        printf("Iteracion %d\n", i);
    }
    imprimir(a, n);
}

void burbujaMejorado(){
    int n = 8;
    int a[8] = {25, 60, 45, 35, 12, 92, 85, 30};
    bool bandera = true;
    for(int i = 0; i < n && bandera; i++){
        bandera = false;
        for(int j = 0; j < n - 1; j++){
            if(a[j] > a[j+1]){
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                bandera = true;
            }
        }
        printf("Iteracion %d\n", i);
    }
    imprimir(a, n);
}
int main(){

    burbuja();

    return 0;
}