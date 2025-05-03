#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    int suma;
    char sim;
    cin >> n >> q;
    short int campo[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> sim;
            switch (sim)
            {
            case '*':
                campo[i][j] = 1;
                break;
            
            case '.':
                campo[i][j] = 0;
                break;

            default:
                break;
            }
        }
    }

    for(int k = 0; k < q; k++){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1-=1;x2-=1;y1-=1;y2-=1;

        for(int i = y1; i <= y2; i++){
            for(int j = x1; j <= x2; j++){
                suma += campo[i][j];
            }
        }

        printf("%d\n", suma);
        suma = 0;
    }

    return 0;
}