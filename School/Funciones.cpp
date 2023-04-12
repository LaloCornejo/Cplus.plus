#include<iostream>
#include<stdio.h>
#include<locale>

void portada(void);
void IMC(float peso, float altura);
void cuadrado(int tam, char car);
void configuracion(void);
void despedida(void);
//void configuracion2(void);
//void configuracion3(void);

//using namespace std;

int main() {
    int x, y, R, tam;
    float peso, altura, R_imc, s, t;
    char car;

    configuracion();

    std::cout << "\n\n\t\t**  F U N D A M E N T O S  E N  P R O G R A M A C I O N  **\n\n\n";

    portada();
    std::cin.get();
    system("clear");

    do{
    std::cout << "\n\n";
    std::cout << "\t\t*******************************\n";
    std::cout << "\t\t**  Incide de masa corporal  **\n";
    std::cout << "\t\t*******************************\n";
        std::cout << "\t\tIngrese su peso(kg): "; std::cin >> peso; std::cout << peso;
        if(!std::cin.fail()){
            std::cout << "\t\tIngrese su altura(mt): "; std::cin >> altura; std::cout << altura;
            if(!std::cin.fail()) {
                std::cout << "\n";
                IMC(peso, altura);
            }else {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "\t\tEl valor ingresado de altura es invalido\n";
                std::cin.get();
                system("clear");
            }
        }else {
            std::cin.clear();    
            std::cin.ignore(10000,'\n');
            std::cout << "EL valor ingresado de peso es invalido\n";
            std::cin.get();
            system("clear");
        }
    }while(peso <= 30 || peso > 250 || altura <= 0 || altura > 2.50);

    std::cout << "\n\t\t";
    std::cin.clear();

    std::cout << "\n\n";
    std::cout << "\t\t*******************************\n";
    std::cout << "\t\t**    Dibujando Figuritas    **\n";
    std::cout << "\t\t*******************************\n";

        std::cout << "\t\tDe que tamano desea el cuadrado: "; std::cin >> tam;
        if(!std::cin.fail()) {
        std::cout << "\t\tCual seria el caracter? "; std::cin >> car;
            if(!std::cin.fail()) {
                cuadrado(tam, car);
            }else {
                std::cout << "\n\t\tEl valor ingresado no es valido\n";
            }
        }else{
            std::cout << "\n\t\tEl valor ingresado no es valido\n";
        }

    std::cout << "\n\n\n";
    std::cin.get();

    despedida();

    return 0;
}

void portada() {
    system("clear");
    std::cout << "\t\t\t**   *     *    *     **** *  *   **\n";
    std::cout << "\t\t\t**   *     *   * *    *    *  *   **\n";
    std::cout << "\t\t\t**   *     *  *   *   ***  ****   **\n";
    std::cout << "\t\t\t**   *     * *******  *    *  *   **\n";
    std::cout << "\t\t\t**    ***** *       * **** *  *   **\n";
    std::cout << "\t\t\t\t\tICBI\n";
    std::cout << "\t\t    Area academico de computacion y electronica\n";
    std::cout << "\t\t     Licenciatura en Ciencias Computacionales\n";
    std::cout << "\t\t\t  Jesus Eduardo Cornejo Clavel\n";
    std::cout << "\t\t\t\t       377355\n";
    std::cout << "\t\t\t\tSem: 1        Grup: 1\n";
}

void configuracion() {
    setlocale(LC_CTYPE, "Spanish");
}

void IMC(float peso, float altura) {
    float cal_imc;
    std::cout << "\n";

    cal_imc = peso/(altura*altura);

    if(cal_imc < 18.5){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " DESNUTRICION\n";
    std::cout << "\n";
    }
    else if(cal_imc>=18.5 && cal_imc <= 24.99){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " NORMAL\n";
    std::cout << "\n";
    }
    else if(cal_imc >=25 && cal_imc<=29.99){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " SOBREPESO\n";
    std::cout << "\n";
    }
    else if(cal_imc >=30 && cal_imc<=34.99){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " OBESIDAD I\n";
    std::cout << "\n";
    }
    else if(cal_imc >=35 && cal_imc<=39.99){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " OBESIDAD II\n";
    std::cout << "\n";
    }
    else if(cal_imc >=40){
    std::cout << "\t\tSu clasificacion es: " << cal_imc << " OBESIDAD III\n";
    std::cout << "\n";
    }
}

void cuadrado(int tam, char car) {
    for(int i = 0; i < tam; i++) {
        std::cout << "\t\t";
        for(int i = 0; i < tam; i++) {
        std::cout << car << " ";
        }
        std::cout << "\n";
    }
}

void despedida() {
    std::cout << "\t\t***********************************************\n";
    std::cout << "\t\t**  Aplicacion eleaborada por: Lalo Cornejo  **\n";
    std::cout << "\t\t**  Datos de contacto: co377355@uaeh.edu.mx  **\n";
    std::cout << "\t\t***********************************************\n";
}