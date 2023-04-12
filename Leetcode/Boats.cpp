#include<iostream>
#include<math.h>

using namespace std;
int main() {
    int x = 50000;
    int jk, i, j, count = 0;
    int people[x], limit, boat = 0;
    cin >> people[x];
    cin >> limit;

    for(int h = 0; h < x; h++){
        for(int v = 0 + h; v < x; v++){
            if(people[h] > people[v]){
                jk = people[v];
                people[v] = people[h];
                people[h] = jk;
            }
        }
    }

    for(int m = 0; people[m] != 0; m++){
        count ++;
    }

    for(int i =0; i < count;i++) {
        cout << people[i] << " ";
    }

    return 0;
}