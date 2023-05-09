#include<iostream>
#include<string>
#include <conio.h>
#include<Windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void welcome();
void instructions();
void record();
void incorrectChoice();
void lostgame();
void win();

bool game = false;
const int width = 50;
const int height = 20;


int x, y, fx, fy, score;

int tx[100], ty[100];
int nt;

enum Direction {STOP = 0, LEFT , RIGHT, UP, DOWN};
Direction dir;

void Init() {
    game = true;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand()% width;
    fy = rand()% height;
    score = 0;
    tx[100] = {};
    ty[100] = {};
}

void Map() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 180);
    for(int  i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
                cout << "#";
            if(i == y && j == x)
                cout << "o";
            else if(i ==fy && j ==fx)
                cout << "x";
            else{
                bool print = false;
                for( int k = 0; k < nt;k++){
                    if(tx[k] == j && ty[k] == i){
                        cout << "o";
                        print = true;
                    }
                }

                if(!print)
                    cout << " ";
            }

            if(j == width - 1)
                cout << "#";
        }

        cout << "\n";
    }

    for(int i = 0; i< width + 2; i++)
        cout << "#";
        cout << "\n";
        cout << "Score is: " << score << "\n";
}

void Input(){
    if(_kbhit()) {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        
        case 's':
            dir = DOWN;
            break;
        
        case 'w':
            dir = UP;
            break;

        case 'd':
            dir = RIGHT;
            break;
        
        case 'x':
            game = false;
            break;
        
        case 'r':
            dir = STOP;
            break;

        default:
            break;
        }
    }
}

void Logic() {
    int prevx = tx[0];
    int prevy = ty[0];
    int prev2x, prev2y;
    tx[0] = x;
    ty[0] = y;
    for (int i = 0; i < nt; i++){
        prev2x = tx[i];
        prev2y = ty[i];
        tx[i] = prevx;
        ty[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch(dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }

    if( x >= width) 
        x = 0; 
    else if (x< 0) 
        x = width - 1;
    
    if( y >= height) 
        x = 0; 
    else if (x< 0) 
        x = height - 1;

    for(int i = 0 ; i < nt; i++){
        if(tx[i] == x && ty[i] == y){
            lostgame();
        }
    }
    

    if(x == fx && y == fy) {
        score += 1;
        nt++;
        fx = rand() % width;
        fy = rand() % height;
    }
}

void win() {
    if(score == 100) {
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "                           ";
        cout << "** Congratulations you wnd the game  **";
        cout << "\n\n\n\n\n";
        cout << "                           ";
        cout << "** To play agane enter any key  **";
        char back;
        cin >> back;

        if(back) {
            welcome();
            game = false;
        }
    }
}

void startGame() {
    Init();
    while(game) { 
        Map();
        Input();
        Logic();
        win();
        Sleep(10);
    }
}

void welcome() {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "                   ";
    cout << "**  Welcome to the snake game  **\n\n";
    cout << "\t\t\t\t1. If you want play the game press 1\n";
    cout << "\t\t\t\t2. If you want to see the intructions press 2\n";
    cout << "\t\t\t\t3. To see recor press 3\n";

    char choise; cin >> choise;
    switch(choise) {
        case '1':
            system("cls");
            startGame();
        case '2':
            instructions();
        case '3':
            record();
        default:
            incorrectChoice();
    }
}

void instructions() { 
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "                   ";
    cout << "**  Welcome to the snake game  **\n\n";
    cout << "\t\t\t\t\t** I N S T R U C T I O N S  **\n\n\n";
    cout << "\t\t\t\t1. If you reach current record u win\n";
    cout << "\t\t\t\t2. When you grow u cant touch ur self\n";
    cout << "\t\t\t\t\t To go back press any key\n";
    char back;
    cin >> back;

    if(back) welcome();
}

void record() {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "                   ";
    cout << "**  Welcome to the snake game  **\n\n";
    cout << "\t\t\t\t\t** R E C O C R D **\n\n\n";
    cout << "\t\t\t\tCurrent recor is: 100\n";
    cout << "\t\t\t\t\t To go back press any key\n";
    char back;
    cin >> back;

    if(back) welcome();
}

void incorrectChoice() {
    cout << "Please try agane next tiume\n\n";
    cout << "\t\t\t\t\t To go back press any key\n";
    char back;
    cin >> back;

    if(back) welcome();
}

void lostgame() {
    game = false;
    system("cls");
    cout << "\t\t\t\tU lost dumbass\n";
    cout << "\t\t\t\t\t Ur score was: " << score << "\n";
    cout << "\t\t\t\t\t To go back press any key\n";
    char back;
    cin >> back;

    if(back){
        game = false;
        welcome();
    } 
}
 int main (){
    SetConsoleTextAttribute(hConsole, 116);
    welcome();
    return 0;
 }