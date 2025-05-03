#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);

    int l = frase.length();

    stack<char> s;
    queue<char> q;

    for(int i = 0; i < l; i++){
        if(isalpha(frase[i])){
            s.push(toupper(frase[i]));
            q.push(toupper(frase[i]));
        }
    }

    bool palindromo = false;

    while(!s.empty() && !q.empty()){
        if(s.top() == q.front()){
            s.pop();
            q.pop();
            palindromo = true;
        }else{
            palindromo = false;
            break;
        }
    }

    if(palindromo)
        cout << "Es palindromo\n";
    else
        cout << "No es palindromo\n";
}