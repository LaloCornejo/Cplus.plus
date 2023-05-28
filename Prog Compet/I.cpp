#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;

    cin >>n >> m >> k;

    //Canute = m
    //Keit = n

    if(n / k > m){
        printf("Iron fist Ketil\n");
    }else  if(n / k < m){
        printf("King Canuten\n");
    }

    return 0;
}