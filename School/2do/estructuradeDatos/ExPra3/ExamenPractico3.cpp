// L Æ L O

// TIENDITA
#include<iostream>
#include<fstream>
#include<list>
#include<locale>

using namespace std;

struct Venta {
    int id;
    list<string> productos;
    list<float> precio;
    float total = 0;
};


void ticket(Venta venta) {
    ofstream file;
    file.open(to_string(venta.id) + ".txt");
    auto it = venta.productos.begin();
    auto it2 = venta.precio.begin();
    for (; it != venta.productos.end() && it2 != venta.precio.end(); ++it, ++it2) {
        file << *it << "  " << *it2 <<"\n";
    }
    file << "Total: " << venta.total;
    file.close();
}

void almacenarVenta(Venta venta) {
    ofstream file;
    file.open("ventas.txt", ios::app);
    file << venta.id << "\n";
    auto it = venta.productos.begin();
    auto it2 = venta.precio.begin();
    for (; it != venta.productos.end() && it2 != venta.precio.end(); ++it, ++it2) {
        file << *it << "  " << *it2 <<"\n";
    }
    file << venta.total << "\n";
    file << "----------------\n\n";
    file.close();
}

void ingresarVenta(list<Venta>& ventas) {
    Venta venta;
    cout << "Ingrese el id de la venta: ";
    cin >> venta.id;
    cout << "Ingrese los productos de la venta: \n";
    string producto;
    float precio;
    while ( cin >> producto && producto != "-1" ) {
        venta.productos.push_back(producto);
        cin >> precio;
        venta.precio.push_back(precio);
    }

    for(auto& precio : venta.precio) {
        venta.total += precio;
    }
    ventas.push_back(venta);
    almacenarVenta(venta);
    ticket(venta);
}

void print_ticket(Venta venta) {
    cout  << "______________________________\n";
    cout << "| ID: " << venta.id << "\n";
    auto it = venta.productos.begin();
    auto it2 = venta.precio.begin();
    for (; it != venta.productos.end() && it2 != venta.precio.end(); ++it, ++it2) {
        cout << "|\t" << *it << "  " << *it2 << "\n";
    }
    cout  << "|\n|    ----------------------   \n";
    cout << "|\tTotal: " << venta.total << "\n";
    cout  << "______________________________\n\n\n";
}

void cleanTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    while( 1 ){
        list<Venta> ventas;
        ingresarVenta(ventas);

        print_ticket(ventas.front());


        // cleanTerminal();
    }

    return 0;
}