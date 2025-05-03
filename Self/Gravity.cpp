#include<iostream>
#include<string>
#include<math.h>
#include<random>
#include<conio.h>
#include<Windows.h>
#include<ctime>


//void menu();
void Init();
void StartSimul();
void Map();
void funcionesLineales();
void funcionesLinealesV();
void funcinesCuadraticas();
void Input();
void Gravity();
void Friction();
void Logic();
void Data();
void DataLineal();
void DataLinealY();
void DataCuadratica();
void fps();


const int width = 100;
const int height = 14;
const int soil_lvl = height-1;
int FPS = 0, refresh = 0;
;

int gravity = 0, acelerationV = 0, acelerationH = 0;

bool simulator = false, cuadratica = false, linealV = false;
int x, y, x_inicial, x_final, op, acelerationVI, y_inicial, y_final;
char movements[20];
//Lineal
int m, xf;

//Cuadratica
int prevy;
float h;

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
            if(i == height - y_final && cuadratica == true && j == h && linealV==false)
                std::cout << "*";
            if(linealV == true && i == height - y_final && j == xf && cuadratica==false)
                std::cout << "*";
            if(i == height && j == x_inicial && j != x)
                std::cout << "#";
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
    linealV=false;
    m = 0; xf = height-y;
}

void funcionesLinealesV(){
    cuadratica=false;
    linealV = true;
    m = 0; xf = x_final;
}

void funcionesCuadradas(){
    cuadratica = true;
    linealV=false;
}   

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a': case 'A':
            if(acelerationH == 0)
                x_inicial=x;
            if(acelerationH > -4 && height - y == 0)
                acelerationH -= 2;
            if(height-y==0)
                funcionesLineales();
            break;
            case 'd': case 'D':
            if(acelerationH == 0)
                x_inicial=x;
            if(acelerationH < 4 && height - y == 0)
                acelerationH += 2;
            if(height-y==0)
                funcionesLineales();
            break;
            case 'w': case 'W':
            if(height - y == 0){
                h = 999;
                acelerationV += 2 + rand() % 3;
                acelerationVI = acelerationV;
                x_inicial = x;
                if(acelerationVI < 4){
                    y_final = acelerationVI;
                }
                if(acelerationVI == 4){
                    y_final = acelerationVI+2;
                }
                if(acelerationH > 0 ||  acelerationH < 0){
                    funcionesCuadradas();
                }
                if(acelerationH == 0)
                    funcionesLinealesV();
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
    if(cuadratica==true && acelerationV == 0){
        prevy = (y-1)-height;
    }
    if(prevy == - 1 && height-y == 0){
        acelerationH = 0;
    }
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
        prevy = 0;
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


void Data(){
    std::cout << "\t\t\t\t\t\t\t  Y: " << (height-y) << "  X: " << x;
    std::cout << "\n\t\t\t\t\t\tAceleracion H: " << acelerationH << "  Aceleracion V: " << acelerationV;

}

void DataLineal(){
    if(cuadratica == false && linealV == false){
        std::cout << "\n\t\t\t\t\t\t         F(x) = "  <<  m << "x + " << xf;
        std::cout << "\n\t\t\t\t\t\t\t  d(A, B) = " << sqrt(pow(x_final - (x_inicial), 2)+pow((y_final - y_inicial), 2));
    }
        
}

void DataLinealY(){
        y_inicial = height-y;
        std::cout << "\n\t\t\t\t\t\t         F(y) = "  <<  m << "y + " << xf;
        std::cout << "\n\t\t\t\t\t\t\t  d(A, B) = " << sqrt(pow((x_final - x_inicial), 2)+pow((y_final - y_inicial), 2));
}

void DataCuadratica(){
    float h1, h2, k, x_max, x_min;
    
        int y2, x2;
        float a;
        if(x_inicial > x_final){
            x_max = x_inicial;
            x_min = x_final; 
        }
        if(x_inicial < x_final){
            x_max = x_final; 
            x_min = x_inicial; 
        }
            h1 = x_max - ((x_max - x_min) / 2);
            h2 = ((x_max - x_min) / 2) + x_min;
            if(h1 == h2){
                h = h1;
            }else{
                h = (abs(abs(h2)-abs(h1))/2);
            }
            k = y_final;
            a = (0- k) / pow((x_inicial - h), 2);
        std::cout << "\n\t\t\t\t\t\t\t    V(" << h << ", " << k << ")" << "\n\t\t\t\t\t        F(x) = "  << a << "( " << "x - " << h << " )^2 + " <<  k  ;
}

void fps(){
    float seconds = clock()/1000;
    FPS = refresh / seconds;
    std::cout << "FPS: " << FPS << " Seconds: " << clock()/1000;
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
        Data();
        if(cuadratica==false && linealV==false)
            DataLineal();
        if(cuadratica==false && linealV==true)
            DataLinealY();
        if(cuadratica==true && linealV==false)
            DataCuadratica();
        std::cout << "\n\t\t\t\t\t\t         x1 = "  << x_inicial << " x2 = "  << x_final << "\n";

        fps();
        refresh++;
        
    }
}

/*void menu(){
    system("cls");
    std::cout << "\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t\t\t\t\t**** Elige el modo de simula ****\n";
    std::cout << "\t\t\t\t\t\t*******   1. Open world   *******\n";
    std::cout << "\t\t\t\t\t\t---------------------------------\n";
    std::cout << "\t\t\t\t\t\t\tOpcion: "; std::cin >> op;
    std::cout << "\n\n\t\t\t\t\tSalir de la simulacion presiona la tecla 'z' .-.";

    switch(op){
        case 1:
            StartSimul();
            break;
        
    }
}*/

int main(){
    std::cin.tie(NULL);   

    StartSimul();
}