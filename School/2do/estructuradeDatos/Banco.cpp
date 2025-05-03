#include<iostream>
#include<cstdio>

using namespace std;

class cuenta_bancaria{
private:
    string nombre;
    double saldo;

public:
    cuenta_bancaria();
    void deposito(double);
    void retiro(double);
    void consultar_saldo();
};

cuenta_bancaria::cuenta_bancaria(){
    cin >> nombre;
    saldo = 0;
}

void cuenta_bancaria::deposito(double cantidad){
    saldo += cantidad;
}

void cuenta_bancaria::retiro(double cantidad){
    if(saldo >= cantidad){
        saldo -= cantidad;
    }else{
        cout << "No hay suficientes fondos\n";
    }
}

void cuenta_bancaria::consultar_saldo(){
    cout << saldo << "\n";
}

int main(){
    cuenta_bancaria p1;

    p1.consultar_saldo();
    p1.deposito(1000);
    p1.consultar_saldo();
    p1.retiro(999);
    p1.consultar_saldo();
    p1.retiro(2);
    p1.consultar_saldo();

    return 0;
}