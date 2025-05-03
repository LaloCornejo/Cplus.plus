#include<iostream>
#include<locale>
#include<string.h>
#include<math.h>


void conociendo_aputadores(void);
void caracteres(void);
void par_imp(int *num);
void cubo(double *num);

int main () {
    int N; 
    double num;

    //system("clean");
    setlocale(LC_CTYPE, "Spanish");
    conociendo_aputadores();
    //system("clean");

    std::cout << "Ingrese el valor a identificar: ";
    std::cin >> N;
    std::cout << "\n";
    par_imp( &N );
    std::cout << "\n\n";
        
    //system("clean");
    std::cout << "Ingrese el valor a calcular el cubo: ";
    std::cin >> num;
    std::cout << "\n";
    cubo(&num);
    std::cout << "\n\n";

    //system("clean");
    std::cout << "Manejado caracters y apuntadores \n";
    std::cout << "\n\n";
    caracteres();
    std::cin.get();

    return 0;
}

void conociendo_aputadores(void){
    int i = 567;
    int *p;
    p = &i;

    float e = 2.71727;
    float *q;
    q = &e;

    char vocales[] = {'A', 'E', 'I', 'O', 'U'};
    char *v;
    v = &vocales[0];

    double g = 9.8;
    double *ag;
    ag = &g;

    std::cout << "\t\t ***          A P U N T A D O R E S        ***\n";
    std::cout << "\t\t ---------------------------------------------\n";
    std::cout << "\t\t ***   MOSTRANDO CONTENIDOS Y DIRECCIONES  ***\n";
    std::cout << "\t\t      VALOR/CONTENIDO            DIRECCION    \n";
    std::cout << "\t\t\t"<< *p << "\t\t\t" << &p << "\n";
    std::cout << "\t\t\t"<< *q << "\t\t\t" << &q << "\n";
    std::cout << "\t\t\t"<< *ag << "\t\t\t" << &ag << "\n";
    std::cout << "\t\t\t"<< *v << "\t\t\t" << &vocales << "\n\n";

    std::cin.get();
}

void caracteres(void) {
    char *pc, c;
    pc = &c;

    //system("clean");
    std::cout << "\t\t Mostrabdo algunos caracteres del codigo  \n";
    std::cout << "\t\t Usando variables apuntador...  \n\n\n";

    for(c = 'a'; c <= 'z';c++){
        std::cout << *pc << "   ";
    }
    std::cout << "\n\n";

    std::cin.get();
}

void par_imp(int *num){
    ////system("cls");
    std::cout << "\t\t Identificado si el numero\n";
    std::cout << "\t\t por medio de apuntadores... \n\n\n";
    if(*num == 0){
        std::cout << "\t\t El numeor es Zero\n";
    }else if(*num%2 ==  0){
        std::cout << "\t\t El numeor es Par\n";
    }else if(*num%2 != 0){
        std::cout << "\t\t El numeor es Impar\n";
    }

}

void cubo(double *num){
    double c;
    c = pow(*num, 3);

    std::cout << "\t\t El valor del cubo al numero ingresado es: " << c << "\n";

    std::cin.get();
}
