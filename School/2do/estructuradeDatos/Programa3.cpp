// Author: L Æ L Ö

#include<iostream>
#include<cstdio>
using namespace std;

class Rectangulo {
private:
    int alto;
    int ancho;

public:
    Rectangulo() : alto(3), ancho(3) {}

    Rectangulo(int a, int b) : alto(a), ancho(b) {}

    int perimeter(){
        return 2 * (alto + ancho);
    }

    int area(){
        return alto * ancho;
    }

    void print(){
        for(int i = 0; i < alto; i++){
            for(int j = 0; j < ancho; j++){

                if( i == 0 || i == alto - 1 || j == 0 || j == ancho - 1 ){
                    cout << " * ";
                }else{
                    cout << "   ";
                }
            }
            cout << endl;
        }
    }

};




int main(){
    Rectangulo x;
    Rectangulo y(10, 5);

    printf("\t\n\nRectangulo X: \nPerimetro: %d\nArea: %d\nDibujo: \n\n", x.perimeter(), x.area());
    x.print();

    printf("\t\n\nRecangulo Y: \nPerimetro: %d\nArea: %d\nDibujo: \n\n", y.perimeter(), y.area());
    y.print();
    
    return 0;
}