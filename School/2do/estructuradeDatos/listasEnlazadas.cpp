#include<iostream>
using namespace std;

class nodo{
    public:
        int dato;
        nodo *enlace;
};

class lista_enlazada{
    private:
        nodo *cabecera;
    public:
        lista_enlazada();
        void mostrar();
        void insertarInicio(int);
        void insertar(int);
        void eliminarInicio();
        void eliminarFinal();
        void eliminarLista();
};

lista_enlazada::lista_enlazada(){
    cabecera = NULL;
}

void lista_enlazada::mostrar(){
    if(cabecera){
        nodo *aux = cabecera;
        do{
            cout << aux->dato << " ";
            aux = aux->enlace;
        }while(aux != NULL);
    }
}

void lista_enlazada::insertarInicio(int ingreso){

    nodo *nuevo = new nodo;
    nuevo->dato = ingreso;
    nuevo->enlace = cabecera;
    cabecera = nuevo;
}

void lista_enlazada::insertar(int ingreso){
    nodo *nuevo = new nodo();

    nuevo->dato = ingreso;
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
            nodo * aux1 = cabecera;
            nodo * aux2 = cabecera->enlace;
            while(aux2->enlace != NULL){
                aux1 = aux2;
                aux2 = aux2->enlace;
            }
            aux1->enlace = NULL;
            delete aux2;
        }
    }
}

void lista_enlazada::eliminarLista(){
    if(cabecera){
        nodo *aux = cabecera;
        while(aux){
            cabecera = cabecera->enlace;
            delete aux;
            aux = cabecera;
        }
    }
}