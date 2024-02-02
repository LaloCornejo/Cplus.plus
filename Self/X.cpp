#include <iostream>
#include <string>

using namespace std;

bool esEscalera(int n) {
    string s = to_string(n); // 12321 -> "12321"
    int l = s.length();
    for (int i = 0; i < l/2; i++) {
        if (s[i] != s[ l - i - 1]) {
            return false; // no numero escalera
        }
    }
    return true; // numero escalera
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (esEscalera(n) == true) {
        cout << "es escalera inicialmente";
        return 0;
    }else{
        n = (n - a) / b + 1;
        if (esEscalera(n) == true) {
            cout << "es escalera despues del primer intento";
            return 0;
        }else{
            n = n - ( a + b ) + 1;
            if (esEscalera(n) == true) {
                cout << "es escalera despues del segundo intento";
                return 0;
            }else{
                cout << "nos rendimos";
                return 0;
            }
        }
    }

    return 0;
}

// #include <iostream>

// using namespace std;
// int main(){
//     int a, b, c;
//     cin >> a >> b >> c; // 3 2 1

//     int temp;
//     int iter = 0;
//     int max = a;
//     int posi = 1;

//     if (max < b){
//         max = b;
//         posi = 2;
//     }
//     if (max < c){
//         max = c;
//         posi = 3;
//     }


//     // ===========- max = x --============= a, b, c

//     if(posi == 1){
//         temp = a;
//         a = c;
//         c = temp;
//         iter++;
//     }else if(posi == 2){
//         temp = b;
//         b = c;
//         c = temp;
//         iter++;
//     }


//     // ===========- max = x --============= a, b

//     if (a > b){
//         temp = a;
//         a = b;
//         b = temp;
//         iter++;
//     }

//     cout << iter;
//     return 0;
// }