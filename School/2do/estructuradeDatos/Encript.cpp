#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool isVowel( char m ){
    if(m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u')
        return true;
    return false;
}

int main(){
    stack<char> s;
    queue<char> q;

    string message;
    string F1, F2;

    getline(cin, message);
    int l = message.length();

    for(int i = 0; i < l; i++){
        if(!isVowel(message[i])){
            s.push(message[i]);
        }else {
            while(!s.empty()){
                F1 += s.top();
                s.pop();
            }
            F1 += message[i];
        }
    }

    while(!s.empty()){
        F1 += s.top();
        s.pop();
    }
    
    printf("Fase1: %s\n", F1.c_str());

    for(int i = 0; i < l; i++){
        s.push(F1[i]);
        q.push(F1[i]);
    }

    for(int i = 0; i < l/2; i++){
        F2 += q.front(); q.pop();
        F2 += s.top(); s.pop();
    }

    if(l % 2 != 0)
        F2 += q.front();

    printf("%s\n", F2.c_str());
    return 0;
}