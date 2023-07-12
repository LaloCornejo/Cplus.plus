#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll num;

bool  isPrime(int num){
    
    if(num <= 1)
         return false;

    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) 
            return false;
    }

    return true;
}


int main() {
    ll n;
    cin >> n;
    bool primes[n];
    ll prim = 0;

    for(num = 0; num <= n; num++)
        if(isPrime(num)){
            
            primes[num] = true;
            prim++;    
        }

    printf("Total Primes: %d \n", prim);

}
