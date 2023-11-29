#include<iostream>
#include<fstream>

using namespace std;

class persona{
    private:
        char name[20];
        int age;
    public:
        void leer();
        void imprimir();
};

void persona::leer(){
    cout << "Nombre: ";
    cin >> name;
    cout << "Edad: ";
    cin >> age;
    cin.ignore();
}

void persona::imprimir(){
    cout << "Nombre: " << name << endl;
    cout << "Edad: " << age << endl;
}

void add_registro(){
    ofstream file;
    file.open( "datos.dat", ios::binary | ios::app );
    if( file.fail() ){
        cout << "Error add: " << endl;
        exit(1);
    }

    persona x;
    x.leer();
    file.write( (char *)&x, sizeof(persona) );
    file.close();
}

void show_registro(){
    ifstream file;
    file.open( "datos.dat", ios::binary | ios::in );
    if( file.fail() ){
        cout << "Error read: " << endl;
        exit(1);
    }

    persona x;
    while( file.read( (char *)&x, sizeof(persona) ) ){
        x.imprimir();
    }
    file.close();
}

int main(){
    int opc;
    do{
        cout << "1. Add" << endl;
        cout << "2. Show" << endl;
        cout << "3. Exit" << endl;
        cout << "Option: ";
        cin >> opc;
        switch( opc ){
            case 1: add_registro(); break;
            case 2: show_registro(); break;
            case 3: break;
            default: cout << "Error" << endl;
        }
    }while( opc != 3 );
    return 0;
}
