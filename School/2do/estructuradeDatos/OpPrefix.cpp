#include<iostream>
#include<stack>
#include<cctype>

using namespace std;

int main(){
  stack<int> s;
  string xpre;
  cin >> xpre;

  for(int i = 0; i < xpre.size(); i++){
    char next_item = xpre[i];

    if(isdigit(next_item)){
      s.push(next_item - '0');
      // printf("push %d\n", next_item - '0');
    }
    else{
      int op2 = s.top(); s.pop();
      int op1 = s.top(); s.pop();

      int result;
      switch(next_item){
        case '+': result = op1 + op2; break;
        case '-': result = op1 - op2; break;
        case '*': result = op1 * op2; break;
        case '/': result = op1 / op2; break;
      }

      s.push(result);
    }
  }

  cout << s.top() << endl;

  return 0;
}