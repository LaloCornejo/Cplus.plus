#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    ll t, n, x;
    vector<bool> arr.assign(false);

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> x;


        for(int j = 0; j < n; j++){
            ll temp;
            for( int c = 0; c <= temp; c++){
                ll posi = 1;
                arr[posi] = true;
                posi = temp * c;
            }
        }
    }

    for(int i = 0; i < t; i++){
        if(arr[i] == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}