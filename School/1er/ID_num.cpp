#include<iostream>
#include<locale>

 int main(){    
    double num;

    setlocale(LC_CTYPE, "Spanish");

    std::cout << "\t\t\t********************************\n";
    std::cout << "\t\t\tIdentifica el signo de un numero\n",
    std::cout << "\t\t\t********************************\n";
    std::cout << "\t\tIngrese un numero para su identificacion: "; std::cin >> num;

    std::cout << std::endl;
    
    if(num == 0) {
        std::cout << "\t\tEl zero no posee ningun signo es un valor nul%\n";   }else if( num > 0){
        std::cout << "\t\t__________________________\n";
        std::cout << "\t\t|  El valor es positivo  |\n";
        std::cout << "\t\t__________________________\n";
        std::cout << "\t\tSe posiciona al lado derecho del zero en el plano cartesiano\n";

    }else if(num < 0){
        std::cout << "\t\t__________________________\n";
        std::cout << "\t\t|  El valor es negativo  |\n";
        std::cout << "\t\t__________________________\n";
        std::cout << "\t\tSe posiciona al lado derecho del zero en el plano cartesiano\n";

    }

    return 0;
 }

 
 //Arh¡chivo con PApelido_Inicial SApellido (Cornejo_C)
 //Platafora subes.org.gov

 //Para el jueves: cin.fail, cin.clear, cin.ignore