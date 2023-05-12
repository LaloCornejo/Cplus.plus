#include<iostream>
#include<string>
#include<math.h>
#include<random>
#include<conio.h>
#include<Windows.h>


void welcome();


const int width = 100;
const int height = 14;
const int soil_lvl = height-1;
int FPS = 0;

int gravity = 0, acelerationV = 0, acelerationH = 0;

bool simulator = false, cuadratica = false;
int x, y, x_inicial, x_final, op, acelerationVI;
char movements[20];
//Lineal
int m, xf;

//Cuadratica

enum Direction {STOP = 0, LEFT, RIGHT, UP};
Direction dir;

void Init() {
    simulator = true;
    dir = STOP;
    x = 0;
    y = soil_lvl;

}

void Map(){
    system("cls");
    for(int i =0; i <= height; i++){
        for(int j=-1; j <= width; j++){
            if(j==-1 && height - i < 10)
                std::cout << "\t  " << height - i << " |";
            if(j==-1 && height - i > 9)
                std::cout << "\t " << height - i << " |";
            if(i == y && j == x)
                std::cout << "O";
            if(i == height)
                std::cout << "~";
            else{
                bool print = false;

                if(!print){
                    std::cout << " ";
                }
            }
            if(j == width){
                std::cout << "|";
            }
        }
        std::cout << "\n";
    }
}

void funcionesLineales(){
    cuadratica = false;
    m = 0; xf = height-y;
}

void funcionesCuadradas(){
    cuadratica = true;
}   

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a': case 'A':
            if(acelerationH > -4)
                acelerationH -= 2;
            if(height-y==0)
            funcionesLineales();
            break;
            case 'd': case 'D':
            if(acelerationH < 4)
                acelerationH += 2;
            if(height-y==0)
            funcionesLineales();
            break;
            case 'w': case 'W':
            if(height - y == 0){
                acelerationV += 2 + rand() % 3;
                acelerationVI = acelerationV;
                x_inicial = x;
                funcionesCuadradas();
            }
            break;
            default:
            break;
        }
    }
} 

void Gravity(){
    gravity = 1;
        y += gravity;
        if(y == 13)
            gravity = abs(gravity);
    if(acelerationV > 0){
        acelerationV -= abs(gravity);
    }
}

void Friction(){
    if(height - y == 0 && acelerationH > 0){
        acelerationH--;
    }
    if(height - y == 0 &&  acelerationH < 0){
        acelerationH++;
    }
}

void Logic(){
    if(acelerationH < 0){
        x+=acelerationH; 
    }
    if(acelerationH > 0){
        x+=acelerationH; 
    }
    if(acelerationV > 0){
        y -= acelerationV;
    }

    if(y >= soil_lvl)
        y = soil_lvl;
    if(x >= width){
        x = width;
        acelerationH = 0;
    }
    if(x <= 0){
        x = 0;
        acelerationH = 0;
    }
    if(x_inicial != x && (acelerationH == 0 || y == soil_lvl)){
        x_final = x;
    }
    if(cuadratica==true && acelerationH!=0 && height - y == 0)
        acelerationH = 0;
}


void StartSimul(){
    Init();
    while(simulator){
        gravity = 0;
        Map();
        Input();
        Logic();
        Gravity();
        Friction();
        std::cout << "\t\t\t\t\t\t\t  Y: " << (height-y) << "  X: " << x;
        std::cout << "\n\t\t\t\t\t\tAceleracion H: " << acelerationH << "  Aceleracion V: " << acelerationV;
        if(cuadratica == false){
            std::cout << "\n\t\t\t\t\t\t         F(x) = "  <<  m << "x + " << xf;
            std::cout << "\n\t\t\t\t\t\t\t  d(A, B) = " << sqrt(pow(x_final - (x_inicial), 2)+pow(y - y, 2));
        }
        if(cuadratica == true){
            int y2, x2, h, k, x_max;;
            float a;
            if(x_inicial > x_final)
                x_max = x_inicial; 
            if(x_inicial < x_final)
                x_max = x_final; 
                h = x_max - (abs(x_inicial - x_final) / 2);
                k = acelerationVI;
                a = (x_inicial-k)/ pow(h, 2);
            std::cout << "\n\t\t\t\t\t\t\t     V(" << h << ", " << k << ")" << "\n\t\t\t\t\t        F(x) = -"  << a << "( " << "x - " << h << " )^2 + " <<  k  ;
        }
        std::cout << "\n\t\t\t\t\t\t         x1 = "  << x_inicial << " x2 = "  << x_final << "\n";
    FPS++;
    std::cout << "FPS: " << FPS;
    }
}

void menu(){
    std::cout << "**** Elige el modo de simula ****\n";
    std::cout << "********* 1. Open world *********\n";
    std::cout << "*********** 2. Battle ***********\n";
    std::cout << "---------------------------------\n";
    std::cout << "\tOpcion: "; std::cin >> op;

    switch(op){
        case 1:
            StartSimul();
            break;
        
    }
}

int main(){
    std::cin.tie(NULL);   

    StartSimul();
}