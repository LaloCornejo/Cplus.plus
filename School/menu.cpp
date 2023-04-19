#include<iostream>
#include<math.h>
#include<locale>
#include<stdlib.h>
#include<stdio.h>

//using namespace std;

int main() {
    
    char op;
    const double pi=3.141592;
    double rad, bMax, bMin, alt, dMax, dMin, Area;

    //system("cls");
    setlocale(LC_CTYPE, "Spanish");

    std::cout << "\t\t\n\n";
    std::cout << "\t\t*******************************\n";
    std::cout << "\t\t**   Areas de fiuras planas  **\n";
    std::cout << "\t\t*******************************\n\n";

    std::cout << "\t\t*******************************\n";
    std::cout << "\t\t**    1), C), c) Circulo     **\n";
    std::cout << "\t\t**    2), T), t) Trapecio    **\n";
    std::cout << "\t\t**    3), R), r) Rombo       **\n";
    std::cout << "\t\t**    0), Q), q) Salir       **\n";
    std::cout << "\t\t*******************************\n\n";

    std::cout << "\t\tIngresa la opcion a elegir: "; std::cin>>op;

    switch(op) {
    
        case '1':   case 'C': case 'c':
            //system("cls");
            std::cout << "\t\t\n\n";
            std::cout << "\t\t*******************************\n";
            std::cout << "\t\t**      Area del círculo     **\n";
            std::cout << "\t\t*******************************\n\n";

            std::cout << "\t\tInrgese el valor del radio: "; std::cin>> rad;
                
                if(!std::cin.fail() && rad > 0 ){
                    Area = pi * pow(rad, 2);
                    std::cout << "\t\t\n\nEl área del círculo es: " << Area << "\n";
                }else {
                    std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                    std::cout << "\t\tEl valor ingresado es un caracter o es un valor <= 0\n";
                }
        break;
        

        case '2':   case 'T': case 't':
            //system("cls");
            std::cout << "\t\t\n\n";
            std::cout << "\t\t*******************************\n";
            std::cout << "\t\t**     Area del trapecio     **\n";
            std::cout << "\t\t*******************************\n\n";

            std::cout << "\t\tIngrese el valor de la base menor: "; std::cin >> bMin;
                if(!std::cin.fail() && bMin > 0){
                    std::cout << "\t\tIngrese el valor de la base mayor: "; std::cin >> bMax;
                    if(!std::cin.fail() && bMax > 0){
                        std::cout << "\t\tIngrese el valor de la Altura: "; std::cin >> alt;
                        if(!std::cin.fail() && alt > 0){
                            Area = (bMax + bMin)*alt/2;
                            std::cout << "\t\t\n\nEl area del trapecio es: " << Area << "\n\n";
                        }else {
                            std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                            std::cout << "\t\tEl valor ingresado de <<Altura>> es un caracter o es un valor <= 0\n";
                        }
                    }else {
                        std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                        std::cout << "\t\tEl valor ingresado de <<Base mayor>> es un caracter o es un valor <= 0\n";
                    }
                }else {
                    std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                    std::cout << "\t\tEl valor ingresado de <<Base menor>> es un caracter o es un valor <= 0\n";
                }
        break;
        

        case '3':   case 'R': case 'r':
            //system("cls");
            std::cout << "\t\t\n\n";
            std::cout << "\t\t*******************************\n";
            std::cout << "\t\t**       Area del rombo      **\n";
            std::cout << "\t\t*******************************\n\n";

                std::cout << "\t\tIngrese el valor de la Diagonal mayor: "; std::cin >> dMax;
                if(!std::cin.fail() && dMax > 0){
                    std::cout << "\t\tIngrese el valor de la Diagonal menor: "; std::cin >> dMin;
                    if(!std::cin.fail() && dMin > 0) {
                        Area = (dMax * dMin)/2;
                        std::cout << "\t\t\n\nEl area del Rombo es: " << Area << "\n";
                    }else{
                        std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                        std::cout << "\t\tEl valor ingresado de <<Diagonal Menor>> es un caracter o es un valor <= 0\n";
                    }
                }else{
                    std::cout << "\t\t\n\n<<<<<<<<<<<<<<<<       INVALIDO         >>>>>>>>>>>>>>>\n";
                    std::cout << "\t\tEl valor ingresado de <<Diagonal Mayor>> es un caracter o es un valor <= 0\n";
                }
        break;


        case '0':   case 'Q': case 'q':
            //system("cls");
            std::cout << "\t\t\n\n";
            std::cout << "\t\t*************************************************\n";
            std::cout << "\t\t**            Gracias por usar la app          **\n";
            std::cout << "\t\t**   Contacto: lalocornejoofficial@gmail.com   **\n";
            std::cout << "\t\t**            Dev: L Æ L O                     **\n";
            std::cout << "\t\t*************************************************\n";
        break;

        default:
            system("cls");
            std::cout << "\t\t\n\n";
            std::cout << "\t\t************************************\n";
            std::cout << "\t\t**         Opcion incorrecta      **\n";
            std::cout << "\t\t**         Lee bien el menu       **\n";
            std::cout << "\t\t************************************\n";
        break;
    }//Cierre de swithc

    
    return 0;
}//Cierre main()