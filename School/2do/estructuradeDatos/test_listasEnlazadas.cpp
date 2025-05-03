#include <iostream>
#include "listasEnlazadas.cpp"

using namespace std;

int main(){
    lista_enlazada lista;

    // Test case 1: Deleting an empty list
    lista.eliminarLista();

    // Test case 2: Deleting a list with one node
    lista.insertar(1);
    lista.mostrar();
    lista.eliminarLista();
    lista.mostrar();

    // Test case 3: Deleting a list with multiple nodes
    lista.insertar(1);
    lista.insertar(2);
    lista.insertar(3);
    lista.mostrar();
    lista.insertarInicio(15);
    lista.mostrar();
    lista.eliminarLista();

    cout << "All tests passed!" << endl;

    return 0;
}