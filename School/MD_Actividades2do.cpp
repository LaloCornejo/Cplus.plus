//                     PROGRAMA 1

#include <iostream>
#include <math.h>

using namespace std;
int main() {
    int val;
    int dif;
    int vala;
    int n;
    int vali;
    int r;
    char op;

     char resp;
     cout << "******************************************\n";
     cout << "**    Sucesion aritmetica/geometrica    **\n";
     cout << "******************************************\n\ n";

     do {
        cout << "\t\t*************************\n";
        cout << "\t\t**    1. aritmetica    **\n";
        cout << "\t\t**    2. geometrica    **\n";
        cout << "\t\t*************************\n";
        cin >> resp;
        switch(resp) {
            case '1':
                cout << "Ingrese el valor inicial: "; cin >> val;
                cout << "Ingrese la diferencia: "; cin >> dif;
                cout << "Ingrese el cuantos nuemeros quiere: "; cin >> n;
                
                cout << "\n";

                for(int i = 1; i <= n; i++) {
                    cout << "a" << i << " = " << val << "\n";
                    vala = val;
                    val = vala + dif;
                }
                
            break;
            
            case '2':
                cout << "Ingrese valor inicial: "; cin >> vali;
                val = vali;
                cout << "Ingrese el valor de r: "; cin >> r;
                cout << "Ingrese el cuantos nuemeros quiere: "; cin >> n;
                for(int j = 1; j <= n; j++) {
                    val = pow(r, (j - 1))*vali;
                    cout << "a" << j << " = " << val << "\n";
                }
            break;
        }
        
        cout << "\n\n\t\tDeseas repetirlo(y/n): "; cin >> op;

     } while (op == 'y');
     
    return 0;
}


/*                      PROGRAMA 2

#include <iostream>

using namespace std;

int main() {
    int x;
    cout<< "Ingrese cuntos numeros quiere para la sumatoria: ";
    cin >> x;
    int num[x];
    int resp;
    int a;
    int d;
    cout<< "******************************************\n";
    cout<< "**    Suamatoria progresion aritmetica    **\n";
    cout<< "******************************************\n\n";
    
    cout<< "Ingrese cual es el valor inicial: ";
    cin >> a;
    cout<< "Ingrese cual es la diferencia: ";
    cin >> d;
    num[0] = a;

    for(int i = 1; i <= x; i++){
        num[i] = num[i - 1] + d;
    }
    
    for(int j = 0; j < x; j++){
        cout << " + " << num[j];
        resp += num[j];
    }
    
    cout << " = " << resp;
    
    return 0;
}
*/

/*                     PROGRAMA 3

#include<iostream>
#include<math.h>

using namespace std;
int main() {
    int n;
    int a1;
    int r;
    int resul;
    cout << "********************************************\n";
    cout << "**    Suamatoria progresion geometrica    **\n";
    cout << "********************************************\n\n";

    cout << "Ingrese el valor de \"n\": "; cin >> n;
    cout << "Ingrese el primer valor(a1): "; cin >> a1;
    cout << "Ingrese el valor de \"r\": "; cin >> r;
    
    resul = ( a1 * ( pow(r, n) - 1 ) ) / ( r-1 );

    cout << "EL valor de a" << n << " es: " << resul << "\n";

    return 0;
}
*/