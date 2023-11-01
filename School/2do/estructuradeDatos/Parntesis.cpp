#include<iostream>
#include<stack>

using namespace std;

bool Pares(char abre,char cierra)
{
    if(abre == '(' && cierra == ')') return true;
    else if(abre == '{' && cierra == '}') return true;
    else if(abre == '[' && cierra == ']') return true;
    return false;
}

bool Balance(string expr)
{
    stack<char> S;
    for(int i =0;i<expr.length();i++)
    {
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            S.push(expr[i]);
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if(S.empty() || !Pares(S.top(),expr[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true:false;
}

int main()
{
    string expresion;
    cin>>expresion;
    if(Balance(expresion))
        cout<<"Balanceado\n";
    else
        cout<<"No Balanceado\n";
}