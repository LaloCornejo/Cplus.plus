#include<bits/stdc++.h>

using namespace std;

int main(){
    int repe = 0;
    int n;
    cin >> n; int a[n], NAMEs=n;
    int estatus[n];
    char NAME[n][20];

    for (int i = 0; i < n; i++){
        cin >> a[i];
        string entrada_nom[n][a[i]];
        for(int j = 0; j < a[i]; j++){
            cin >> entrada_nom[i][j];
        }
        
        for(int j = 0; j < a[i]; j++){
            NAME[i][j] = entrada_nom[i][j][0];
        }
        estatus[i] = 1;

    }
    

    for(int i =0; i < n; i++){
        for(int j =0; j < a[i]; j++){
            for(int i2 = 0; i2 < n; i2++){
                if(NAME[i][j] == NAME[i2][j] && i2 != i){
                    estatus[i] = 1;
                    estatus[i2] = 1;
                    break;
                }
                if(NAME[i][j] != NAME[i2][j]){
                    estatus[i] = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(estatus[i] == 0)
            repe++;
    }
    cout << repe << "\n";
}