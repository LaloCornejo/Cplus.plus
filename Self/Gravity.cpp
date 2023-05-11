#include<iostream>
#include<string.h>
#include<math.h>
#include<random>
#include<conio.h>
#include<Windows.h>


void welcome();


const int width = 165;
const int height = 14;
const int soil_lvl = height-2;
int gravity = 0;
float acelerationV = 0, acelerationH = 0;

bool simulator = false;
float x, y;
int op;

int tx[9400], ty[9400];

enum Direction {STOP = 0, LEFT, RIGHT, UP};
Direction dir;

void Init() {
    simulator = true;
    dir = STOP;
    x = 1;
    y = soil_lvl;

}

void Map(){
    system("cls");
    std::cout << "\n\n\n\n\n\n";
    for(int i =0; i <= height; i++){
        for(int j=0; j <= width; j++){
            if(j==0)
                std::cout << "\t  |";
            if(i == y && j == x)
                std::cout << "x";
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

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a': case 'A':
            if(acelerationH > -4)
                acelerationH -= 2;
            break;
            case 'd': case 'D':
            if(acelerationH < 4)
                acelerationH += 2;
            break;
            case 'w': case 'W':
            if(y == 13)
                acelerationV += rand() % 6;
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
    if(y == 13 && acelerationH != 0 && acelerationH > 0){
        acelerationH--;
    }else if(y == 13 && acelerationH != 0 &&  acelerationH < 0){
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
    if(x >= width - 1)
        x = width - 1;
    if(x <= 0)
        x = 0;
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
        std::cout << "\t\t\t\t\t\t\t\t\t\t  Y: " << y << "  X: " << x;
        std::cout << "\n\t\t\t\t\t\t\t\t\tAceleracion H: " << acelerationH << "  Aceleracion V: " << acelerationV;
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