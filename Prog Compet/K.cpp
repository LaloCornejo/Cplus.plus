#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    k = k-1;
    int map[n][n];

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            cin >> map[j][i];
        }
    }

    int posi = 0;
    for( int j = 0; j < n; j++){
        for(int i  =0; i< n; i++){
            if(map[j][i] == map[j][i+k] && j + k < n && i + k < n){
                if(map[j][i] == map[j+k][i]){
                    if(map[j][i] == map[j+k][i+k]){
                        posi++;
                        map[j][i] = -1;
                    }
                }
            }
        }
    }

    printf("%d\n", posi);

    return 0;
}