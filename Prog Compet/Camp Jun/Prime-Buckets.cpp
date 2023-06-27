#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
    ll n;
    cin >> n;
    bool primes[n];
    ll prim = 0;

    for(int i = 0; i < n; i++) {
        if((fact(n - 1) + 1) % n == 0) {
            primes[i] = true;
            cout << i << "\n";
            prim++;
        }else {
            primes[i] = false;
        }
    }

    cout << prim << "\n";
}