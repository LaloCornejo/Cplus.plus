#include <iostream>
#include <string>
#include <algorithm>
#include<locale>
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

class Lista {
public:
    Persona* personas; // Arreglo dinámico
    int n;
    int MAX;

    Lista(int max) {
        MAX = max;
        n = 0;
        personas = new Persona[MAX];
    }

    ~Lista() {
        delete[] personas;
    }

    void agregar_persona(Persona persona) {
        if (n < MAX) {
            personas[n] = persona;
            n++;
            cout << "Persona agregada correctamente." << endl;
        }else cout << "La lista está llena :l" << endl;
    }

    void mostrar_lista() {
        if(n > 0){
            for (int i = 0; i < n; i++) {
                cout << "Persona " << i + 1 << ":" << endl;
                personas[i].mostrar_datos();
                cout << endl;
            }
        }else cout << "La lista está vacia :l" << endl;
    }

    void ordenar_lista_seleccion() {
        if(n > 0){
            for (int i = 0; i < n - 1; i++) {
                int min = i;
                for (int j = i + 1; j < n; j++) {
                    if (personas[j].apellido_paterno < personas[min].apellido_paterno) {
                        min = j;
                    }
                }
                swap(personas[i], personas[min]);
            }
        }else cout << "La lista esta vacia :l" << endl;
    }

    void ordenar_lista_insercion() {
        if(n > 0){
            for (int i = 1; i < n; i++) {
                Persona persona_actual = personas[i];
                int j = i - 1;
                while (j >= 0 && persona_actual.apellido_paterno < personas[j].apellido_paterno) {
                    personas[j + 1] = personas[j];
                    j--;
                }
                personas[j + 1] = persona_actual;
            }
        }else cout << "La lista esta vacia :l" << endl;
    }

    void ordenar_lista_burbuja() {
        if(n > 0){
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (personas[j].apellido_paterno > personas[j + 1].apellido_paterno) {
                        swap(personas[j], personas[j + 1]);
                    }
                }
            }
        }else cout << "La lista esta vacia :l" << endl;
    }
};

void clean(){
    // This is for Windows
    //system("cls");    
    // This is for Mac or Linux
    //system("clear");  
}

int main() {
    Lista lista_personas(7);
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
            lista_personas.agregar_persona(nueva_persona);
            break;
        }
        case 2: {
            clean();
            lista_personas.mostrar_lista();
            break;
        }
        case 3:{
            char opcionOrdenar;
            clean();
            cout << "** MENU DE ORDENAMIENTO **" << endl;
            cout << "a. Ordenamiento por seleccion" << endl;
            cout << "b. Ordenamiento por insercion" << endl;
            cout << "c. Ordenamiento por burbuja" << endl;
            
            cin >> opcionOrdenar;
            
            switch (opcionOrdenar)
            {
            case 'a':{
            lista_personas.ordenar_lista_seleccion();
            lista_personas.mostrar_lista();
                break;
            }
            case 'b':{
            lista_personas.ordenar_lista_insercion();
            lista_personas.mostrar_lista();
                break;
            }
            case 'c':{
            lista_personas.ordenar_lista_burbuja();
            lista_personas.mostrar_lista();
                break;
            }
            }
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
