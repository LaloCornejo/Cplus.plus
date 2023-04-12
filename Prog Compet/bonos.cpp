#include<iostream>

using namespace std;

int main() {
    int n, m, bono, y, c;
    cin>> n >> m;

    int num[n][n] ; 
    int i = 0;



    bono = m-((n*n)-1);

        num[n/2][n/2] = m;
 
        while(bono < m) {
            for(int x = n-(i+1); x >= i; x--) {
                num[i][x] = bono;
                bono += 1;
            }
            for(int y = i + 1; y < n-(i+1); y++) {
                num[y][i] = bono;
                bono += 1;
            }
            for(int x = i; x < n - i; x++) {
                num[n-(i+1)][x] = bono;
                bono += 1;
            }
            for(int y = n - (i + 2); y > i; y--) {
                num[y][n-(i+1)] = bono;
                bono += 1;
            }
            
            i++;
        }
            

        for(int a=0; a < n; a++ ){
            for(int b=0; b< n; b++){
                cout << num[a][b] << " ";
            }
            cout << "\n";   
        }

    return 0;
}