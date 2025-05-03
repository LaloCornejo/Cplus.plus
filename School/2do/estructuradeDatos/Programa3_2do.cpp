#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <locale>
using namespace std;

class Persona {
public:
    string nombre;
    string apellido_paterno;
    string apellido_materno;
    int edad;

    Persona() {
        nombre = "";
        apellido_paterno = "";
        apellido_materno = "";
        edad = 0;
    }

    void mostrar_datos() {
        cout << "Nombre: " << nombre << " " << apellido_paterno << " " << apellido_materno << endl;
        cout << "Edad: " << edad << endl;
    }

    void leer_datos() {
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Apellido paterno: ";
        getline(cin, apellido_paterno);

        cout << "Apellido materno: ";
        getline(cin, apellido_materno);

        cout << "Edad: ";
        cin >> edad;
    }
};

void clean(){
    // This is for Windows
    //system("cls");    
    // This is for Mac or Linux
    //system("clear");  
}

int main() {
    list<Persona> lista_personas;
    bool con = true;

    while (con) {
        cout << "\nOpciones del menu:" << endl;
        cout << "1. Anadir una nueva persona" << endl;
        cout << "2. Mostrar la lista de personas" << endl;
        cout << "3. Ordenar la lista de personas" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            Persona nueva_persona;
            nueva_persona.leer_datos();
            lista_personas.push_back(nueva_persona);
            break;
        }
        case 2: {
            clean();
            if(lista_personas.empty()){
                cout << "La lista está vacia :l" << endl;
            }else{
                int i = 1;
                for(auto it = lista_personas.begin(); it != lista_personas.end(); it++){
                    cout << "Persona " << i << ":" << endl;
                    it->mostrar_datos();
                    cout << endl;
                    i++;
                }
            }
            break;
        }
        case 3:{
            lista_personas.sort([](const Persona& a, const Persona& b){
                return a.apellido_paterno < b.apellido_paterno;
            });
            break;
        }
        case 4:{
            con = false;
            break;
        }
        }
    }

    return 0;
}