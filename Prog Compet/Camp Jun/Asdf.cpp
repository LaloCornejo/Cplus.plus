#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, q, enf=0;
    cin >> t >> q ;
    char nn[t];
    int suma[t], repe=0;

    for(int i = 0; i < t; i++){
        cin >> nn[i];
        if(i-1 >= 0){
            if(nn[i] == nn[i-1]){
                repe++;
                suma[i] = repe;
            }else
                suma[i] = suma[i-1];
        }else
            suma[i] = 0;
    }

    for(int c = 0; c < q; c++){
        int L, R;
        cin >> L >> R;
        L  = L - 1; R = R - 1;

        enf = suma[R] - suma[L];

        printf("%d\n", enf);
        enf = 0; 
    }
    return 0;
}