#include<iostream>
using namespace std;

class nodo{
    public:
        int dato;
        nodo *enlace;
}

class lista_enlazada{
    private:
        nodo *cabecera;
    public:
        lista_enlazada();
        void mostrar();
        void insertarInicio();
        void insertar();
        void eliminarInicio();
        void eliminarFinal();
}

void lista_enlazada::lista_enlazada(){
    cabecera = NULL;
}

void lista_enlazada::mostrar(){
    if(cabecera){
        nodo *aux = cabecera;
        do{
            cout << aux->dato << " ";
            aux = aux->enlace;
        }while(aux->enlace != NULL);
    }
}

void lista_enlazada::insertar_i(){
    nodo nodo;
    nodo *nuevo = new nodo;
    cin >> nuevo->dato;
    nuevo->enlace = cabecera;
    cabecera = nuevo;
}

void lista_enlazada::insertar(){
    nodo *nuevo = new nodo();

    cin >> nuevo->dato;
    nuevo->enlace= NULL;

    if(cabecera == NULL){
        cabecera = nuevo;
    }else{
        nodo *aux = cabecera;
        while(aux->enlace != NULL)
            aux = aux->enlace;

        aux->enlace = nuevo;
    }
}

void lista_enlazada::eliminarInicio(){
    if(cabecera){
        nodo *aux = cabecera;
        cabecera = cabecera->enlace;
        delete aux;
    }
}

void lista_enlazada::eliminarFinal(){
    if(cabecera){
        if(cabecera->enlace == NULL){
            nodo * aux = cabecera;
            cabecera = NULL;
            delete aux;
        }else{
            nodo * aux2 = cabecera;
            do{
                aux1 = aux2;
                aux2 = aux2->enlace;
            }while(aux->enlace != NULL);

            aux1->enlace = NULL;
            delete aux2;
        }
    }
}