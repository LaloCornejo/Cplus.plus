#include <iostream>
#include <string>

using namespace std;

bool esEscalera(int n) {
    string s = to_string(n);
    int l = s.length();
    for (int i = 0; i < l/2; i++) {
        if (s[i] != s[ l - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (esEscalera(n)) {
        cout << "es escalera inicialmente";
        return 0;
    }else{
        n = (n - a) / b;
        if (esEscalera(n)) {
            cout << "es escalera despues del primer intento";
            return 0;
        }else{
            n = (n - a) + b;
            if (esEscalera(n)) {
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