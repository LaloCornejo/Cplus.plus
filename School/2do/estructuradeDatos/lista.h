#include<iostream>
using namespace std;

class lista{
    private: 
    int *a;
    int n;
    int MAX;

public:
    lista(int);
    ~lista();
    void mostrar_l();
    void mostrar_e();
    void buscar_e();
    void anadir_e();
    void insertar_e();
    void eliminar_e();
    void eliminar_todo_e();
    void app();
}
