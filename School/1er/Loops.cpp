#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<locale>
//#include<windows>

int main() {

    char op, resp;
    int r, c, u, a, t, Num, cub, e, z;
    int Re, x, y = 1;

    do { //Repeticion de programa
     do {
        //system("cls");
        setlocale(LC_CTYPE, "Spanish");
        std::cout << "\n\n";
        std::cout << "\t*********  CILOS/BUCLES  *********\n";
        std::cout << "\t**********************************\n";
        std::cout << "\t s) Sucesion 2^n        \n";
        std::cout << "\t t) Tabla de multiplicar\n";
        std::cout << "\t g) Generador de tiempo \n";
        std::cout << "\t a) Numeros aleatorios  \n";
        std::cout << "\t c) Numeros Cuadraticos \n";
        std::cout << "\t u) Numeros Cubicos     \n";
        std::cout << "\t p) Numeros Pares     \n";
        std::cout << "\t i) Numeros Impares     \n";
        std::cout << "\t q) Salir               \n";
        std::cout << "\t**********************************\n\n";
        
        std::cout << "\tElige la opcion: "; std::cin >> op;
     }while(op != 's' && op != 't' && op != 'g' && op != 'a' && op != 'c' && op != 'u' && op != 'q' && op != 'p' && op != 'i');//validacion op menu

     switch(op){
        case 's':
            for(int i = 0; i < 10; i++){
                r = pow(2, i);
                std::cout << "\t2^" << i << "=" << r << "\n";
            }
        break;
        case 't':
            std::cout << "Ingrese de que numero quiere la tabla: "; std::cin >> x;
                if(!std::cin.fail()){
                    for(int y = 1; y <= 10; y++){
                        Re = x*y;
                        std::cout << "\t" << x << " * " << y << " = " << Re << "\n";
                    }
                    std::cout << "\n";
                }else { 
                    std::cout << "El valor ingresado es invalido!!! ";
                }
        break;
        case 'g':
            for(int m = 0; m < 35536; m++){
                for(int n = 0; n < 35536; n++){
                    //consumo del tiempo del CPU
                }
            }
        break;
        case 'a':
            for(int q = 0; q < 15; q++){
                Num = rand();
                std::cout << "\t" << Num << "\n";
            }
        break;
        case 'c':
            for(int p = 0; p < 10; p++){
                c = p*p;
                std::cout << "\t" << c << "\n";
            }
        break;
        case 'u':
            for(int i = 0; i < 10; i++){
                u = pow(i, 3);
                std::cout << "\t" << i << "^3 = " << u << "\n";
            }        
        break;
        case 'q':
            std::cout << "\n\n";
            std::cout << "\t Gracias por usar la aplicacion\n";
            std::cout << "\t Dato de contacto laloconejoofficial@gmail.com\n";
        break;
        case 'p':
        std::cout << "\tIngrese cunatos numeros pares quiere: "; std::cin >> e;
            if(!std::cin.fail() && e >= 0 ){
                for(int i = 1; i <= e; i++){
                    std::cout << i << ". " << i * 2 << "\n";              }
            }else { 
                std::cout << "\tEl valor ingresado es invalido!!! \n";
            }
        break;
        case 'i':
        std::cout << "\tIngrese cunatos numeros impares quiere: "; std::cin >> z;
            if(!std::cin.fail() && z >= 0){
                int imp = 1;                
                for(int j = 0; imp <= z; j++)
                    if(j%2 != 0){
                        std::cout << imp << ". " << j << "\n";
                        imp++;
                }
            }else {
                std::cout << "\tEl valor ingresado es invalido!!! \n";
            }
        break;
     }//switch
     
        std::cout << "\t**********************************\n";
      std::cout << "\n\tDesea repetir el programa(y/n) : "; std::cin >> resp;
    } while(resp == 'y');

    return 0;
}