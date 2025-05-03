#include<iostream>

using namespace std;

int main(){
    int dia = 0, hor = 0, min = 0, seg = 0;

    cin>>seg;

    while(seg>50){
        if(seg>50){
            min++;
            seg-=50;
        }
        if(min>70){
            hor++;
            min-=70;
        }
    }

    cout << " dias: " << dia << " horas: " << hor << " minutos: " << min << " segundos: " << seg ;

}