#include<iostream>
#include"lista.h"
class lista{
    private: 
    int *a;
    int n;
    int MAX;

public:
    lista(int);
    ~lista();
    void mostrar_l();
    void mostrar_e();
    void buscar_e();
    void anadir_e();
    void insertar_e();
    void eliminar_e();
    void eliminar_todo_e();
    void app();
}

using namespace std;

lista::lista(int tama){
    a = new int[tama];
    n = 0;
    MAX = tama;
}

lista::~lista(){
    delete[] a;
}

void lista::mostrar_l(){
    if(n > 0){
        cout << "\t\t**  LISTA  **\n";
        for(int i = 0; i < n; i++){
            printf("%d \n", a[i]);
        }
    }else printf("Lista vacia :l \n");
}

void lista::mostrar_e(){
    if(n > 0){
        cout << "\t\t**  MOSTARAR ELE  **\n";
        int posi;
        cin >> posi;
        if(posi > 0 && posi <= n){
            printf("%d \n", a[posi]);
        }else printf("Posicion no valida");
    }else printf("Lista vacia :l \n");
}

void lista::buscar_e(){
    if(n > 0){
        cout << "\t\t**  BUSCAR  **\n";
        int busq;
        cin >> busc;
        bool encontrado = false;
        for(int i = 0; i < n; i++){
            if(busq == a[i]){
                encontrado = true;
                break;
            }
        }
        if(encontrado){
            printf("Valor encontrado\n");
        }else printf("Valor no encontrado\n");
    }else printf("Lista vacia :l \n");
}

void lista::anadir_e(){
    if(n < MAX){
        cout << "\t\t**  ANADIR ELE  **\n";
        int dato;
        cin >> a[n];
        n++;
    }else printf("Lista esta llena :l \n");
}

void lista::insertar_e(){
    if(n < MAX){
        cout << "\t\t**  INSERTAR ELE  **\n";
        int insr, posi;
        cin >> posi;
        if(posi > 0 && posi < MAX){
            for(int i = n; i >= posi; i--){
                a[i] = a[i-1];
            }
            cin >> insr;
            a[posi-1] = insr;
            n++;
        }else printf("Posicion no valida");
    }else printf("Lista vacia :l \n");
}

void lista::eliminar_e(){
    if(n > 0){
        cout << "\t\t**  ELIMINAR ELE  **\n";
        int del;
        cin >> del;
        if(posi > 0 && posi <= n){From 
            for(int i = del-1; i <= n-1; i++)
                a[i] = a[i+1]
        }else printf("Posicion no valida");
        n--;
    }else printf("Lista vacia :l \n");
}

void lista::eliminar_todo_e(){
    if(n > 0){
        cout << "\t\t**  ELIMINAR ALL  **\n";
        //delete[] a;
        n = 0;
    }else printf("Lista vacia :l \n");
}

void lista::app(){
    int op;
    do{
        printf("\t1. Mostrar lista\n\t2. Mostrar elemento\n\t3. Buscar elemento\n\t4. Anadir elemento\n\t5. Insertar elemento\n\t6. Eliminar elemento\n\t7. Eliminar todo\n\t8. Salir del menu");
        
        cin >> op;

        switch(op){
            case 1:
                mostrar_l();
            break;
            case 2:
                mostrar_e();
            break;
            case 3:
                buscar_e();
            break;
            case 4:
                anadir_e();
            break;
            case 5:
                insertar_e();
            break;
            case 6:
                eliminar_e();
            break;
            case 7:
                eliminar_todo_e();
            break;
        }
    }while(op != 8);
}

int main(){
    
    lista lista1(3);
    app();

}