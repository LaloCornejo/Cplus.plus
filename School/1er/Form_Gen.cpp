#include<iostream>
#include<math.h>
#include<locale>

int main () {

    double a, b, c, x1, x2, Discri;

    system("cls");
    setlocale(LC_CTYPE, "Spanish");
    std::cout << "\n\n\n";
    std::cout << "\t*******************************************************\n";
    std::cout << "\t   Formula general para operaciones 2de segundo grado\n";
    std::cout << "\t*******************************************************\n\n\n";

    std::cout << "\tIngrese el valor de coeficiente (a): ";
    std::cin >> a;

    if(not(std::cin.fail()) and a != 0 ){ 
        std::cout << "\n\tIngrese el valor del coeficiente (b): ";
        std::cin >> b;
        if(!std::cin.fail()){
            std::cout << "\n\tIngrese el valor del coeficiente (c): ";
            std::cin >> c;
            if(!std::cin.fail()){
                Discri = pow(b, 2)-(4*a*c);
                std::cout << "\tDiscriminante = " << Discri << "\n";
                if(Discri >= 0) {
                    x1 =(-b + sqrt(Discri)) / (2*a);
                    x2 =(-b - sqrt(Discri)) / (2*a);
                    std::cout << "\tDiscriminante = " << Discri << "\n";
                    std::cout << "\tLas soluciones son: x1 : " << x1 << "\t" << "x2: " << x2 << "\n";
                    std::cout << "\n\n\n";
                }else {
                    std::cout << "\n\n";
                    std::cout << "\tLas soluciones no pertenecen a los numeros reales\n\tsino a los NUMEROS COMPLEJOS...\n";
                }//Ciere discri
            }else {
                std::cout << "\tEL valor de coeficiente (c) no es correcto...\n\n";
            }//cierre "c"
        }else {
            std::cout << "\tEl valor del coeficiente(b) no es correcto... \n\n";
        }//cierre "b"
    }else {
        std::cout << "\tEl valor del coeficiente(a) no es valido\n";
    }//cierre "a"

    std::cout << "\t";
    //system("pause");

    return 0;
}//cierre de main