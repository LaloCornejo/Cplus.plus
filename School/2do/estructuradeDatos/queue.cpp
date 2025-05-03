// FIFO (First In First Out)
#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<char> c;
    
    c.push('a');
    c.push('@');
    c.push('#');
    c.push('p');
    c.push('Q');

    cout << "Frente: " << c.front() << "\n";
    cout << "Back: " << c.back() << "\n";

    while(!c.empty() ){
        cout <<  "Eliminado: " << c.front() << "\n";
        c.pop();
    }
}