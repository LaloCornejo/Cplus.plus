// Estructura tipo LIFO (Last nt First Out)
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> p;

    p.push(0);
    p.push(21);
    p.push(50000);

    cout <<  "Cima" << p.top() << "\n";

    while(!p.empty()){
        cout << "Eliminando" << p.top() << "\n";
        p.pop();
    }
}