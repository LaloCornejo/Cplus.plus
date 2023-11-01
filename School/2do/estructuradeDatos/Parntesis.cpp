#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<char> pila;
    string mensaje;

    getline(cin, mensaje);

    int l = mensaje.length();

    for(int i = 0; i < l; i++){
        if(mensaje[i] == '(' || mensaje[i] == ')' || mensaje[i] == '[' || mensaje[i] == ']' || mensaje[i] == '{' || mensaje[i] == '}'){
            pila.push('(');
        }
    }
}

