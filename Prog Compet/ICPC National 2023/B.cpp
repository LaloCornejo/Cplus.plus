#include<iostream>
#include<algorithm>
#define ll long long int
#define si short int

 using namespace std;

int main(){
    int n;
    ll C = 0 , E = 0;
    bool w = 0;

    cin >> n;
    ll Nn = n * 3;
    int numbers[Nn];

    for(int i = 0; i < Nn; i++){
        cin >> numbers[i];
    }

    for(int i = Nn-1; i >= 2; i--){
        for(int i = 0; i < Nn; i++){
            cout << numbers[i];
        }

        sort(numbers, numbers + Nn);
        // Carlitos
        C += numbers[i];
        numbers[i] = 0;
        // Equalizer
        E += numbers[i-1];
        numbers[i-1] = 0;
        numbers[i-2] = 0;
        cout << endl;
    }   

    printf("%lld %lld", C, E);

    if(C != E)
        w = 1;

    if(w == 0){cout << "Y\n";}
    else cout << "N\n";
}