#include<iostream>

using namespace std;

int main() {
    int n, form, n_1 = 1, n_2 = 2;
    cin>> n;
    
    for(int i =0; i < n ; i++){
        form = n_1 + n_2;
        n_1 = n_2;
        n_2 = form;
    }
    cout << form;
    return 0;
}