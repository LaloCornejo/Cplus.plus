#include<iostream>
#include<fstream>
using namespace std;

void lectura();
void escritura();

int main(){
    escritura();
    lectura();
}

void escritura(){
    // int n;
    // cin >> n;
    // int arr[n];
    // for( int i = 0; i < n; i++ ){
    //     cin >> arr[i];
    // }
    // FILE *archivo;
    // archivo = fopen("archivo.txt", "wb");
    // fwrite(arr, sizeof(int), n, archivo);
    // fclose(archivo);
    ofstream a;

    a.open("prueba.txt", ios::out);
    if ( a.fail() ){
        cout << "No arch\n";
        exit(1);
    }
    a << "Hola";
    a.close();
}›

void lectura(){
    ifstream a;
    a.open( "prueba.txt", ios::in);
    if( a.fail() ){
        cout << "No arch\n";
        exit(1);
    }

    string text;

    while( !a.eof() ){
        getline(a, text);
        cout << text;
    }
}