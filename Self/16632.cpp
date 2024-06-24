#include<iostream>
#include<string>
using namespace std;
int main(){
  string entrada;
  string Bogota = "",  Cairo = "";

  cin >> entrada;

  for(int i = 0; i < entrada.length(); i++){
    if(entrada[i] != ':'){
      Cairo += entrada[i];
    }
  }
  entrada = "";
  cin >> entrada;
  for(int i = 0; i < entrada.length(); i++){
    if(entrada[i] != ':'){
      Bogota += entrada[i];
    }
  }

  stoi(Bogota);
  stoi(Cairo);

  if(Bogota > Cairo){
    cout << "Bogotá";
  }else if(Cairo > Bogota){
    cout << "El Cairo";
  }
}