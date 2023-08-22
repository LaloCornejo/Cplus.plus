#include<iostream>
#include<string.h>
#include<locale>
//#include<windows>
#include<stdio.h>

int main() {
    char resp;
    char password[30] = {"Fuckingpassword"};
    char password_u[30];

    //system('cls');
    setlocale(LC_CTYPE, "Spanish");
    
    std::cout << "\n\n\n"; 
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t**********            PASSWORD             ************\n";
    std::cout << "\t\t*******************************************************\n";

    std::cout << "\n\tIngrese la password: ";
    std::cin.getline(password_u, 30);
    std::cout << "\n";

    if( strcmp(password, password_u) == 0 ){
        std::cout << "\t\t****************************************************************\n";
        std::cout << "\t\t**********           B I E N V E N I D O            ************\n";
        std::cout << "\t\t****************************************************************\n";
        std::cout << "\n\t\tContinuar con la aplicacion!!!";
        system("open /Users/lalocornejo/Dropbox/Coding/Code C++/menu");
    } else if(strcmp(password, password_u) != 0){
        std::cout << "\n";
        std::cout << "\t\t*******************************************************\n";
        std::cout << "\t\t**********       InvAlID PassWoRd          ************\n";
        std::cout << "\t\t*******************************************************\n\n\n";
        exit(-1);
       }

}


//gets();
//cin.getline();
//strcmp();