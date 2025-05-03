#include<iostream>
#include<cstdio>
using namespace std;

double operacion(int, int, char);


int main(){
    int a, b;
    char sim;
    double result;

    cin >> a >> b >> sim;

    result = operacion(a, b, sim);

    printf("resultado = %f", result);

}

double operacion(int a, int b, char sim){

    double result;
    switch(sim){
        case '+':
            result =(double) a + b;
        break;
        case '-':
            result =(double) a - b;
        break;
        case '*':
            result =(double) a * b;
        break;
        case '/':
            result =(double) a / b;
        break;
    }

    return result;
}