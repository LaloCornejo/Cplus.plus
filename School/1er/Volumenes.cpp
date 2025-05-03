#include<iostream>//Funciones de entrada-salida
#include<stdlib.h>//Funcinoes de sistema
#include<math.h>//Funcinoes matematicas
#include<locale>//Idioma espaniol

#define Pi 3.141592
#define G 9.81

//using namespace std;

int main() {// INICIO

float  Vc, Vest, r, h, A;//VARIABLES
    //Decalaracion de las variables, CTE 
    setlocale(LC_CTYPE, "Spanish"),
    std::cout << "\t\t  *** Operaciones aritméticas ***\n";
    std::cout << "\t\t ---------------------------------\n";
    std::cout << "\t\t *** Cálculo de área y volumen ***\n";
    std::cout << "\t\t Ingrese el valor del radio: "; std::cin >> r;
    std::cout << "\t\t Ingrese el valor de la altura: "; std::cin >> h;
    A = Pi*pow(r, 2);
    std::cout << "\t\t El área del círculo es: " << A << "\n";
    std::cout << "\t\t El volumen de la esfera es: " << ((4/3)*Pi*pow(r, 3)) << "\n";
    std::cout << "\t\t -----------------------------------------\n";
    std::cout << "\t\t Ingrese la altura de Cono: "; std::cin>> h;
    std::cout << "\t\t Ingrese el valor de radio: "; std::cin>> r;
    std::cout << "\t\t El voluen del cono es: " << (Pi*h*(r*r)/3) << "\n";

    system("pause");

    return 0;
}//FIN