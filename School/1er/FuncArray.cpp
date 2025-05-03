#include<iostream>
#include<locale>
#include<stdlib.h>

void impresion1(char vocales[5]);
void impresion2(int edades[6]);
void impresion_2d(float calif[6][3]);
void llenar_suel(double sueldos[5]);
void apro_repro(float calif[6][3]);
float promedio_final(float calif[6][3]);

int main() {
    char resp;
    float P;
    double sueldos[5];

    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    int edades[6] = {17, 19, 21, 20, 18, 22};

    float calif[6][3] = {{10.0, 10.0, 10.0},
                         {5.4, 7.0, 6.0},
                         {3.9, 8.2, 7.6},
                         {8.9, 9.0, 7.0},
                         {5.0, 6.4, 8.8},
                         {2.1, 8.8, 9.4}};
    do{
        setlocale(LC_CTYPE, "Spanish");
        system("clean");

        std::cout << "\n\n";
        std::cout << "\t\t\t ****  ARREGLOS  ****";
        std::cout << "\n\n";
        std::cout << "\t\tMostrando las vocales en vertical: \n";
        impresion1(vocales);
        std::cout << "\n\n";
        std::cin.get();


        std::cout << "\n\n";
        std::cout << "\t\tVisualizando las edades mas comunes: \n";
        impresion2(edades);
        std::cout << "\n\n";
        std::cin.get();


        std::cout << "\n\n";
        std::cout << "\t\tMostrando las calificaciones\n";
        impresion_2d(calif);
        std::cout << "\n\n";
        std::cin.get();


        std::cout << "\n\n";
        std::cout << "\t\tIngrese los suledos de 5 trabajadores\n";
        llenar_suel(sueldos);
        std::cout << "\n\n";
        std::cin.get();


        std::cout << "\n\n";
        std::cout << "\t\tObeteniendo el promedio final\n";
        P = promedio_final(calif);
        std::cout << P << "\n\n";
        std::cin.get();

        
        std::cout << "\n\n";
        std::cout << "\t\t Mostrando los numeros de las evaluaciones...\n";
        apro_repro(calif);
        std::cout << "\n\n";
        std::cin.get();

        std::cout << "\t\t Desea reptir la aplicacion(y/n): ";
        std::cin >> resp;
    }while(resp == 'y' || resp  == 'Y');

    return 0;
}

void impresion1(char vocales[5]){
    for(int i=0; i < 5; i++){
        std::cout << vocales[i];
        std::cout << "\n";
    }
}

void impresion2(int edades[6]){
    for(int i = 0; i < 5; i++){
        std::cout << edades[i];
        std::cout << "\n";
    }
}

void impresion_2d(float calif[6][3]){
    for(int fil = 0; fil < 6; fil++){
        for(int col = 0; col < 3; col++){
            std::cout << calif[fil][col] << ", ";
        }
        std::cout << "\n";
    }
}

void llenar_suel(double sueldos[5]){
    double salario;

    for(int i = 0; i < 5; i++){
        std::cout << "\t Sueldo "<< i + 1  << ": " ;
        std::cin>> salario;
        sueldos[i] = salario;
        std::cout << "\n";
    }
        std::cout << "Los sueldos ingresados son: ";
        for(int j = 0; j < 5; j++){
            std::cout << sueldos[j] << ", ";
        }std::cout << "\n\n";
}

float promedio_final(float calif[6][3]){
    float prom, s = 0.0;

    for(int fil = 0; fil < 6; fil++){
        for(int col = 0; col < 3; col++){
            s += calif[fil][col];
        }
    }

    prom = s/18;
    return prom;
}

void apro_repro(float calif[6][3]){
    int si = 0, no = 0;

    for(int fil = 0; fil < 6; fil++){
        for(int col = 0; col < 3; col++){
            if(calif[fil][col] > 6.9 && calif[fil][col] <= 10){
                si++;
            }else if(calif[fil][col] < 7 && calif[fil][col] >= 0){
                no++;
            }
        }
    }
    std::cout << "\n\n";

    std::cout << "El numero de materias acreditadas son: " << si << "\n";
    std::cout << "El numero de materias no acreditadas son: " << no << "\n";
}
