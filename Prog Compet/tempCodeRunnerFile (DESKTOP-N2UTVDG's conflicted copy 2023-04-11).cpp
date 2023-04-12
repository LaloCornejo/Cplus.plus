#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int rep = 1, n, i = 0;
    cin>>n;
    int n2 = pow(2, n);
    int num[n];
    n = n-1;

    for(int i  = 0; i <= n; i ++){
        num[i] = 0;
    }

    for(int  i = 0; i < n2; i++){
        int tot = i;
        int z = 0; 
        while(tot != 0){
            num[n-z] = tot%2;
            z++;
            tot = tot/2;
        }

        for(int m = 0; rep <= 2 ; m++ ){
            if(num[m] == num[m+1]){
                rep++;
            }else {
                rep  = 1;
            }
            if(m+1 == n && rep <=2){
                for(int c = 0; c <= n; c++){
                    cout << num[c];
                }cout << "\n";
            }
        }rep = 1;

    }
}