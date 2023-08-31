// Author: L Æ L Ö

#include<iostream>
#include<cstdio>
#include<locale>

using namespace std;

class Autor {
private: 
    string nombre;
    string apePa;
    string apeMa;

public:
    void leer(){
        cout << "Nombre: ";
        cin >> nombre; 
        cout << "Apellido Paterno: ";
        cin >> apePa;
        cout << "Apellido Materno: ";
        cin >> apeMa;
    }

    void imprimir(){
        cout << "| Autor: ";
        cout << nombre << " " << apePa << " " << apeMa << "\n";
    }
};

class Libro {
private:
    string titulo;
    Autor autor;
    string editorial;
    int anio;
public:
    void leer(){
        cout << "Titulo: ";
        cin >> titulo; //Todo el titulo debe estar junto remplazar los epacios con "_".
        autor.leer();
        cout << "Editorial: ";
        cin >> editorial;
        cout << "Anio de publicacion: ";
        cin >> anio;
    }

    void imprimir(){
        printf("--------------------------------------------\n");
        cout << "| Titulo: " << titulo << "\n";
        autor.imprimir();
        cout << "| Editorial: " << editorial << "\n";
        cout << "| Anio: " << anio << "\n";
        printf("--------------------------------------------\n\n");
    }

    int getAnio(){
        return anio;
    }
};

int main(){

    system("cls");

    int n;
    cout << "Ingrese el numero de libros: ";
    cin >> n;
    Libro *lib = new Libro[n];
    
    int anoBsuqueda;
    bool encontrado = false;

    printf("\n--------------------------------------------\n");
    cout << "\t**  Ingreso de Libros  **\n";
    printf("--------------------------------------------\n");

    for(int i = 0; i < n; i++){
        printf("\nLibro %d: \n", i+1);
        lib[i].leer();
    }

    system("cls");

    printf("--------------------------------------------\n");
    printf("\t**  Datos Libros  **\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < n; i++){
        printf("\nLibro %d: \n", i+1);
        lib[i].imprimir();
    }

    cout << "\n\nIngrese el anio de publicacion de busqueda: ";
    cin >> anoBsuqueda;


    for(int i = 0; i < n; i++){
        if(lib[i].getAnio() == anoBsuqueda){
            if(!encontrado)
                printf("\n\nLibro(s) publicados en el anio %d:\n\n", anoBsuqueda);
            lib[i].imprimir();
            encontrado = true;
        }
    }

    if(!encontrado){
        printf("\n\nNo hay libros registrados de el anio %d.\n", anoBsuqueda);
    }

    delete[] lib;

    return 0;
}