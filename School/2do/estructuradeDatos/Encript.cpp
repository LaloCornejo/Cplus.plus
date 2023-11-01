#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool isVowelOrSpace(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == ' ';
}

void encode(string mensaje) {
    stack<char> s;
    queue<char> q;

    for (char c : mensaje) {
        if (!isVowelOrSpace(c)) {
            s.push(c);
        } else {
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }
            q.push(c);
        }
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }

    cout << endl;
}

int main(){
    string mensaje;

    getline(cin, mensaje);

    encode(mensaje);

    return 0;
}