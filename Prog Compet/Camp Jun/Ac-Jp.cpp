#include<bits/stdc++.h>

using namespace std;

int main(){
    int a=0, ap=0, k=0, n, jp = 0;

    cin >> n;

    while(a < n){
        k = a - ap;
        ap = a;

        if(jp >= 1 && a < n-1){
            if(ap + (k + 1) <= (n-1)){
                a = ap + (k+1);
            }else if( ap + k <= (n-1)){
                a = ap + (k);
            }else if( ap + ( k - 1 ) <= (n-1)){
                a = ap + (k-1);
            }
                jp++;
            
        }else if(jp < 1 || a == n-1){
            a++;
            jp++;

        }
    }

    printf("%d \n", jp);
}