#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

int main() {
    int x = 0;
    cin >> x;
    int numi[x];
    int num_b[x];

    for(int i = 0; i < x; i++){
        num_b[i] = itoa(numi[i], nullptr,10);
        cout << num_b[i] < "\n";
    }

/*    for(int i =0; i < x; i++){
        cin >> numi[i];
        num_b[i] =
        if(numi[i] % 2 != 0){
            numi[i] = 0;
        }
    }*/
/*    int count = 0;
    for(int j = 0; j < x; j++){
        if(numi[j])
            count++;
    }

    cout<< count;
*/
}