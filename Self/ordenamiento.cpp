#include<iostream>

using namespace std;

void ordenamiento(void);

int main () {
    ordenamiento();
    return 0;
}

void ordenamiento() {
    int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int izquierda = 0 , mitad, derecha = 9;
    int num_busqueda;

    cout << "Ingresa el numero a buscar: ";
    cin >> num_busqueda;

    while(mitad != num_busqueda) {
        mitad = izquierda + ((derecha - izquierda)/2);

    }
}