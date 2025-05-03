#include<iostream>
#include<math.h>

using namespace std;

int main() {
    short int n, x=0, rep = 1;
    cin>>n;
    long long int n2 = pow(2, n);

    bool num[n2][n];

    for(int j=n-1; j >= 0;j--){
        for(long long int i=0;i < n2;){
            for(long long int p=0; p < pow(2, x); p++) {
                num[i][j] = false;
                i++;
            }
            for(long long int q=0;q < pow(2, x); q++){
                num[i][j] = true;
                i++;
            }
        }
        x++;
    }
    
    for(long long int i=0; i < n2; i++){
        for(int j = 1; rep <= 2; j++){
            if(num[i][j] == num[i][j-1]){
                rep++;
            }else {
                rep  = 1;
            }           

            if(j == n-1 && rep <=2){
                for(int c = 0;c < n;c++){
                    cout << num[i][c];
                }
                cout << "\n";
            }
       }
       rep = 1;
    }
    return 0;
}