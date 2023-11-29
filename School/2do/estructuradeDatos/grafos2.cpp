// L Æ L O

#include<iostream>
#include<list>
#include<queue>
#include<stack>

/*
    0---1
    | / | \
    4---3---2

    [0] = 1 4
    [1] = 0 2 3 4
    [2] = 1 3
    [3] = 1 2 4
    [4] = 0 1 3
*/

using namespace std;

class grafo{
private:
    list<int> *cdy;
    int nVertices;
public:
    grafo(int);
    ~grafo();

    void addConte( int, int );
    void print();
    void rAmplitud( int );
    void rProfundidad( int );
};

grafo::grafo( int n ){
    nVertices = n;
    cdy = new list<int> [n];
}

grafo::~grafo(){
    delete[] cdy;
}

void grafo::addConte( int u, int v ){
    cdy[u].push_back(v);
    cdy[v].push_back(u);
}

void grafo::print(){
    list<int>::iterator it;
    for( int i = 0; i < nVertices; i++ ){
        for( it = cdy[i].begin() ; it != cdy[i].end(); it++){
            cout << *it << " ";
        }
    }
    cout << "\n";
}

void grafo::rAmplitud( int v ){
    bool vis[nVertices]; // Verices Visitadas

    for( int i = 0; i < nVertices; i++ ){
        vis[i] = false;
    }

    queue<int> q;

    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int aux = q.front();
        q.pop();
        cout << aux << " ";
        list<int>::iterator it;

        for( it = cdy[aux].begin(); it != cdy[aux].end(); it++ ){
            if( vis[ *it ] == false ){
                vis[ *it ] = true;
                q.push( *it );
            }
        }
    }
}


void grafo::rProfundidad( int v ){
    bool visit[nVertices];

    for( int i = 0; i < nVertices; i++)
        visit[i] = false;

    stack<int> s;
    s.push(v);

    while( !s.empty() ){
        int aux = s.top();
        s.pop();
        if( visit[aux] == false ){
            cout << aux << " ";
            visit[aux] = true;
            list<int>::reverse_iterator it; 
            for( it = cdy[aux].rbegin(); it != cdy[aux].rend(); it++ ){ 
                // cout << *it << "\n";
                if( visit[ *it ] == false ){
                    s.push( *it );
                }
            }
        }
    }
}


/*
    0 1 2 3 4
    1 0 4 3 2
    2 1 0 4 3
    3 1 0 4 2
    4 0 1 2 3

    Imprimo origen
    Marco como visitado
    Agrego a la queue
    Mientras la queue no este vacia
        Tomo el primero de la queue
        Recorro sus adyacentes
            Si no estan visitado
                Lo marco como visitado
                Lo agrego a la queue
            En cunanto termine de recorrer los adyacentes
                Imprimo el primero de la queue
                Lo saco de la queue
            l,
*/
 
int main(){
    grafo g(5);
    g.addConte( 0, 1 );
    g.addConte( 0, 4 );
    g.addConte( 1, 2 );
    g.addConte( 1, 3 );
    g.addConte( 1, 4 );
    g.addConte( 2, 3 );
    g.addConte( 3, 4 );

    g.rAmplitud(0);
    cout << "\n";
    g.rProfundidad(3);
}