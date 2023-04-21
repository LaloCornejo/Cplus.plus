#include<iostream>

using namespace std;

int main () {
    int num[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int izquierda = 0 , mitad = 0, longitud = 10, derecha = (longitud - 1);
    int num_busqueda;

    cout << "Ingresa el numero a buscar: ";
    cin >> num_busqueda;

    while(num[mitad] != num_busqueda) {


        mitad = izquierda + ((derecha - izquierda)/2);
        
        if(num[mitad] > num_busqueda){
            derecha  = mitad;
        }else if(num[mitad] < num_busqueda){
            izquierda = mitad;
        }
    }

    cout << "El numero esta en la posicion: " << mitad;

    return 0;
}
