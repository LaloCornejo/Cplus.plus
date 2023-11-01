#include <iostream>
#include <stack>

using namespace std;

int precedence(char op){
    if(op == '#')
        return 0;
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 3;
}

string infixToPostfix(string inf){
    stack<char> s;
    string post = "";
    inf += '#';

    for(char& ka : inf){
        if(isalpha(ka)){
            post += ka;
        } else if(ka == '('){
            s.push('(');
        } else if(ka == ')'){
            while(!s.empty() && s.top() != '('){
                post += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while(!s.empty() && s.top() != '(' && precedence(ka) <= precedence(s.top())){
                post += s.top();
                s.pop();
            }
            s.push(ka);
        }
    }

    while(!s.empty()){
        post += s.top();
        s.pop();
    }

    return post;
}

int main(){
    string inf;

    getline(cin, inf);
    
    cout << infixToPostfix(inf) << "\n";
    return 0;
}