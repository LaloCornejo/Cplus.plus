#include<iostream>
#include<cstdio>

using namespace std;

void intercambio(int &, int &);

int main(){
    int a, b;

    cin >> a >> b;

    intercambio(a, b);

    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}

void intercambio(int &a, int &b){
    int jk;
    jk = a;
    a = b;
    b = jk;
}