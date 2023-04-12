#include<iostream>

using namespace std;

int main(){
    int n, max = 0, res;
    int div[n];
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>div[i];
    }

    for(int j = 0; j < n; j++){
        for(int p = 0 + j; p < n; p++){
            if(div[p] > div[j]){
                max = div[p];
                div[p] = div[j];
                div[j] = max;
            }
        }
    }

    for(int m = 0; m < n-1; m++){
        res += div[m];
    }

        cout << res << "\n";

    return 0;
}