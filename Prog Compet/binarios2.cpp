#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n, rep = 1;
    cin>>n;

    char num[n];
    long long int n2 = pow(2, n);

    for(long long int i = 0; i < n2; i++) {
        itoa(i, num[i], 2);
        for(int j = 1; j-1 < n; j++){
            if(num[j] == num[j-1]){
                rep++;
            }else if (num[j] != num[j-1]){
                rep=1;
            }

            if(j == n-1 && rep <=2){
                for(int m =0; m < n; m++){
                    cout << num[m] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
/*#include <iostream>
using namespace std;

void generateBinaryCombinations(int n) {
    int totalCombinations = 1 << n; 
    string combination;
    short int cero;
    short int uno;
    for (int i = 0; i < totalCombinations; i++) {
        combination = "";
        cero = 0;
        uno = 0;
        for (int j = n - 1; j >= 0; j--) {
            if ((i & (1 << j)) != 0) {
                combination += "1";
                cero = 0;
                uno += 1;
            } else {
                combination +="0";
                cero += 1;
                uno = 0;
            }
            if(cero > 2 || uno > 2){
                break;
            }
        }
        if(cero <= 2 && uno <= 2){
            cout << combination << "\n";
        }
    }
}

int main() {
    int n;
    cin >> n;
    generateBinaryCombinations(n);
    return 0;
}*/