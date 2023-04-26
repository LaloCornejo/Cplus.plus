#include<iostream>
#include<stdio.h>
#include<string.h>
#include<locale>

void ver_info_x(struct Alumno);
void ver_info_y(struct Alumno);

void pedir_dato_w(void);
void tiempito(void);
void configuracion(void);

void prom_mayor(struct Alumno x, struct Alumno y, struct Alumno w);
void nom_largo(struct Alumno x, struct Alumno y, struct Alumno w);
void edad_mayor(struct Alumno x, struct Alumno y, struct Alumno w);
void promedio_mayor_cu(struct Alumno x, struct Alumno y, struct Alumno w){

struct Alumno{
    int ncuenta;
    char nombre[50];
    char fecha_ing[15];
    int sem;
    int grupo;
    int edad;
    float promedio;
    float promedio_p1;
    float promedio_p2;
    float promedio_p3;
};

struct Alumno w;
struct Alumno x = {101010, "Pepito Perez Lopez", "13/12/23", 1, 1, 15, 9.5, 7.3, 9.2, 10};
struct Alumno y = {201020, "Maria Juanita Hernandez", "24/12/23",1, 1, 21, 8.3, 7.5, 8.7, 9.2};

using namespace std;


int main () {
    configuracion();
    cout << "\n\n";

    cout << "\t\t\t **      Estructuras     **\n";
    cout << "\tVisualisacion de lo que contiene la variable tipo struct: \n";
    ver_info_x(x);

    tiempito();

    ver_info_y(y);

    //system("pause");

    configuracion();

    pedir_dato_w();

    tiempito();

    configuracion();

    cout << "Promedios... \n\n";
    prom_mayor(x, y, w);
    nom_largo(x, y, w);
    edad_mayor(x, y, w);
    promedio_mayor_cu(x, y, w);

    return 0;
}

void ver_info_x(struct Alumno x){
    cout << "***********************************************************************\n";
    cout << "No. cuenta: " << x.ncuenta << "\n\n";
    cout << "Nombre: " << puts(x.nombre) << "\n\n";
    cout << "Fecha de ingreso: " << puts(x.fecha_ing) << "\n\n";
    cout << "Semestre: " << x.sem << "\n\n";
    cout << "Grupo: " << x.grupo << "\n\n";
    cout << "Promedio: " << x.promedio << "\n\n";
    cout << "***********************************************************************\n";
    cout << "Tu nombre tiene: " << strlen(x.nombre) << " caracteres.\n\n";
    cout << "Tamano de la estructura Alumno: " << sizeof(Alumno) << "\n\n";
}

void ver_info_y(struct Alumno y){
    cout << "***********************************************************************\n";
    cout << "No. cuenta: " << y.ncuenta << "\n\n";
    cout << "Nombre: " << puts(y.nombre) << "\n\n";
    cout << "Fecha de ingreso: " << puts(y.fecha_ing) << "\n\n";
    cout << "Semestre: " <<  y.sem << "\n\n";
    cout << "Grupo: " <<  y.grupo << "\n\n";
    cout << "Promedio: " <<  y.promedio << "\n\n";
    cout << "***********************************************************************\n";
    cout << "Tu nombre tiene: " << strlen(y.nombre) << " caracteres.\n\n";
    cout << "Tamano de la estructura Alumno: " << sizeof(Alumno) << "\n\n";
    cout << "***********************************************************************\n";
}

void pedir_dato_w(void){
    char n_aux{50}, f_aux{15};

    cout << "Solicitando datos... \n\n";
    cout << "Nombre: "; cin >> w.nombre;
    cout << "Fecha de ingreso: "; cin >> w.fecha_ing;
    cout << "Numero de cuenta: "; cin >> w.ncuenta; cout << "\n";
    cout << "Semestre: "; cin >> w.sem; cout << "\n";
    cout << "Grupo: "; cin >> w.grupo; cout << "\n";
    cout << "Promesdio: "; cin >> w.promedio; cout << "\n\n";

    cout << "***********************************************************************\n";
    cout << "\t **       Mostrando los datos que acaban de ser ingresados...      **\n";
    cout << "***********************************************************************\n";
    cout << "No. cuenta: " << w.ncuenta << "\n\n";
    cout << "Nombre: " << puts(w.nombre) << "\n\n";
    cout << "Fecha de ingreso: " << w.fecha_ing << "\n\n";
    cout << "Semestre: " << w.sem << "\n\n";
    cout << "Grupo: " << w.grupo << "\n\n";
    cout << "Promedio: " << w.promedio << "\n\n";
    cout << "***********************************************************************\n";
    cout << "Tu nombre tiene: " << strlen(w.nombre) << " caracteres.\n\n";
    cout << "Tamano de la estructura Alumno: " << sizeof(Alumno) << "\n\n";
    cout << "***********************************************************************\n";
}

void tiempito(void){
    for(int i = 0; i < 50000; i++){
        for(int j = 0; j < 50000; j++){
        }
    }
}

void configuracion() {
    setlocale(LC_CTYPE, "Spanish");
    system("clean");
    system("cls");
}

void prom_mayor(struct Alumno x, struct Alumno y, struct Alumno w){
    float M;
    if(x.promedio == y.promedio && w.promedio == y.promedio){
        cout << "Los promedios son iguales... \n\n";
    }else if(x.promedio < y.promedio && w.promedio < y.promedio){
    puts(y.nombre);
    M = y.promedio;
    }else if(x.promedio > y.promedio && w.promedio < y.promedio){
    puts(x.nombre);
    M = x.promedio;
    }else if(x.promedio < y.promedio && w.promedio > y.promedio){
    puts(w.nombre);
    M = w.promedio;
    }

    cout << "El promedio con valora mayor es: " << M << "\n\n";
}
void nom_largo(struct Alumno x, struct Alumno y, struct Alumno w){
    if(strlen(x.nombre) == strlen(y.nombre) && strlen(y.nombre) == strlen(w.nombre)){
        cout << "Los nombres tienen la misma longitud... \n";
    }else if(strlen(x.nombre) > strlen(y.nombre) && strlen(y.nombre) < strlen(w.nombre)){
        puts(x.nombre);
        cout << "El nombre mas largo tiene: " << strlen(x.nombre) << " caracteres\n";
    }else if(strlen(x.nombre) < strlen(y.nombre) && strlen(y.nombre) > strlen(w.nombre)){
        puts(y.nombre);
        cout << "El nombre mas largo tiene: " << strlen(y.nombre) << " caracteres\n";
    }else if(strlen(x.nombre) < strlen(y.nombre) && strlen(y.nombre) < strlen(w.nombre)){
        puts(w.nombre);
        cout << "El nombre mas largo tiene: " << strlen(w.nombre) << " caracteres\n\n";
    }
}
void edad_mayor(struct Alumno x, struct Alumno y, struct Alumno w){
    int edadm;
    if(strlen(x.nombre) == strlen(y.nombre) && strlen(y.nombre) == strlen(w.nombre)){
        cout << "Los nombres tienen la misma longitud... \n";
    }else if( x.edad > y.edad && y.edad < w.edad){
        puts(x.nombre);
        edadm = x.edad;
    }else if( x.edad < y.edad && y.edad > w.edad){
        puts(y.nombre);
        edadm = y.edad;
    }else if( x.edad < y.edad && y.edad < w.edad){
        puts(w.nombre);
        edadm = w.edad;
    }

    cout << " La edad mayor es: " << edadm << "\n\n";
}

void promedio_mayor_cu(struct Alumno x, struct Alumno y, struct Alumno w){
    int promx, promy, promw;
    
    if( x.promedio_p1 > x.promedio_p2 && x.promedio_p2 > x.promedio_p3){
        promx = x.promedio_p1;
    }else if( x.promedio_p1 < x.promedio_p2 && x.promedio_p2 > x.promedio_p3){
        promx = x.promedio_p2;
    }else if( x.promedio_p1 < x.promedio_p2 && x.promedio_p2 < x.promedio_p3){
        promx = x.promedio_p3;;
    }
    
    if( y.promedio_p1 > y.promedio_p2 && y.promedio_p2 > y.promedio_p3){
        promy = y.promedio_p1;
    }else if( y.promedio_p1 < y.promedio_p2 && y.promedio_p2 > y.promedio_p3){
        promy = x.promedio_p2;
    }else if( y.promedio_p1 < y.promedio_p2 && y.promedio_p2 < y.promedio_p3){
        promy = y.promedio_p3;;
    }
    
    if( w.promedio_p1 > w.promedio_p2 && w.promedio_p2 > w.promedio_p3){
        promw = w.promedio_p1;
    }else if( w.promedio_p1 < w.promedio_p2 && w.promedio_p2 > w.promedio_p3){
        promw = w.promedio_p2;
    }else if( w.promedio_p1 < w.promedio_p2 && w.promedio_p2 < w.promedio_p3){
        promw = w.promedio_p3;;
    }
}