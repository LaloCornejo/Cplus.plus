#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void welcome();


const int width = 150;
const int height = 10;
const int soil_lvl = height-3;
const int gravity = 1;
const int jump = 5;
int acelev = 0;
int aceleh = 0;

bool simulator = false;
int x, y;

int tx[9400], ty[9400];

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
    std::cout << "\n\n\n\n\n\n";
    for(int i =0; i < height; i++){
        for(int j=0; j < width; j++){
            if(j==0)
                std::cout << "\t\t|";
            if(i == y && j == x)
                std::cout << "x";
            if(i == height-1)
                std::cout << "~";
            else{
                bool print = false;

                if(!print){
                    std::cout << " ";
                }
            }
            if(j == width - 1){
                std::cout << "|";
            }
        }
        std::cout << "\n";
    }
}

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = STOP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            default:
                break;
        }
    }else
        dir = STOP;

} 

void Gravity(){
    y += gravity;
}

void Logic(){
    switch(dir){
        case UP:
            if(!(y<soil_lvl)){
                y-=jump;
            } 
            break;
        case LEFT:
            x-=2;
            break;
        case RIGHT:
            x+=2;
            break;
        default:
            break;
    }

    if(y >= soil_lvl)
        y= soil_lvl;
    if(x >= width - 2)
        x = width - 2;
    if(x <= 0)
        x = 0;
}


void StartSimul(){
    Init();
    while(simulator){
        Map();
        Input();
        Logic();
        Gravity();
    }
}

int main(){
    StartSimul();
}