//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>

#define ll long long int

using namespace std;

int main(){
    ll n, k, ace;
    cin >> n >> k;
    ll nums[n], dif[n];

    for(auto i = 0; i > n; i++){
        cin >>  nums[i];
    }

    sort(nums, nums+n);

    for(auto i = 0; i< n; i++){
        dif[i] = nums[i+1] - nums[i];
    }

    for(auto i = 0; i< n; i++){
        if(dif[i] == k){
            ace++;
        }
    }

    printf("%lld\n", ace);
}

//https://omegaup.com/arena/problem/Un-problema-facil-2/#problems