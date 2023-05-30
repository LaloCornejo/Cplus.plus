#include<bits/stdc++.h>
#define ll long long int 
#define vi vector<int>

using namespace std;

int main(){
    int a=0, ap=0, k=0, n, jp = 0;

    cin >> n;

    while(a < n){
        k = a - ap;
        ap = a;

        if(jp >= 1 && a < n-1){
            if(ap + (k + 1) < (n)){
                a = ap + (k+1);
                cout << "k+1" << k <<"\n";
            }
            else if( ap + k < (n)){
                a = ap + (k);
                cout << "k" << k <<"\n";
            }
            else if( ap + ( k - 1 ) < (n)){
                a = ap + (k-1);
                cout << "k-1" << k <<"\n";
            }
                jp++;
            
        }else if(jp < 1 || a == n-1){
            cout << "asdas\n";
            a++;
            jp++;

        }
        printf("a: %d jp: %d \n", a, jp);
    }

    printf("%d \n", jp);
}

/*int main(){
    int previous=0, current=0, n, jp==0, inicial;

    cin >> n;
    inicial = n;

    while(n > 0){
        if(jp > 1 && n != 1){
            current = inicial - n;
            if()

            swap(previous, current);

        }else{
            n--;
            jp++;
            current = 1;
            swap(previous, current);
        }
    }
}*/