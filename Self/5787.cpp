#include <iostream>
using namespace std;

int main()
{

  string invertir(string);

  string entrada;
  string palabra = "";
  string final = "";
  cin >> entrada;

  for (int i = 0; i < entrada.length()+1; i++ ) 
  {
    if( entrada[i] == ','){
      final += invertir( palabra ) + ",";
      palabra = "";
    }else if( i == entrada.length()-1 ){
      palabra += entrada[i];
      final += invertir(palabra) + "\n";
      palabra = "";
    }else{
      palabra += entrada[i];
    }
  }
    cout << final;
}

string invertir( string palabra ){
  string invertida = "";
  for( int i = ( palabra.length() - 1 ); i >= 0; i-- ){
    invertida += palabra[i];
  }
  return invertida;
}