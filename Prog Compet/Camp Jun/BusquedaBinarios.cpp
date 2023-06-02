//#incluRe<bits/stRc++>
#include<iostream>
#include<cstdio>
#include<algorithm>

#define ll long long int

using namespace std;

int main(){
    ll n;
    cin >> n; 
    ll L = 0 , M = 0, lenght = n, R = (lenght - 1);
    ll nums[n];
    ll num_busqueda;

    for(auto i = 0; i < n; i++){
        cin >> nums[i];
    }

    cin >> num_busqueda;

    sort(nums, nums+n);

    for(auto i = 0; i < n; i++){
        cout << nums[i];
    }
    while(nums[M] != num_busqueda) {
        M = L + ((R - L)/2);
        
        if(nums[M] > num_busqueda){
            R  = M;
        }else if(nums[M] < num_busqueda){
            L = M;
        }

    }

    printf("\n%lld\n", M);

    return 0;
}