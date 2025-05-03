#include <iostream>
using namespace std;
int main() {
  int t, juez[5];
  int correctos = 0;
  int suma = 0;
  cin >> t;

  for (int j = 0; j < 5; j++){
    cin >> juez[j];
  }

  for (int i = 0; i < 5; i++){
    if (juez[i] == t){
      correctos++;
    }
    suma += juez[i];
  }

  cout << correctos << " " << suma << endl;
}