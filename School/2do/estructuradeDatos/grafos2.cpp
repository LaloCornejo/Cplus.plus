// L Æ L O

#include<iostream>
#include<list>
#include<queue>

using namespace std;

class grafo{
private:
    list<int> *cdy;
    int nVertices;
public:
    grafo(int);
    *grafo();

    void addConte( int, int );
    void print();
    void rAmplitud( int );
}

grafo::grafo( int n ){
    nVertices = n;
    cdy = new list<int> (n);
}

grafo::~grafo(){
    delete cdy;
}

void grafo::addConte( int u, int v ){
    cdy[u].push_back(v);
    cdy[v].push_back(u);
}

void grafo::print(){
    list<int>::iterator it;
    for( int i = 0; i < 5; i++ ){
        for( it = cdy[i].begin() ; it != cdy[i].end(); it++){
            cout << *it << " ";
        }
    }
    cout << "\n";
}

void grafo::rAmplitud( int v ){
    bool vis[nVertices.size()] = { false }; // Verices Visitadas

    queue<int> q;

    q.push(v);
    vis[v] = true;

    while(!c.empty()){
        int aux = q.front();
        q.pop();
        cout << aux << " ";
        list<int>::iterator = *it;

        for( it= q[aux].begin(); it != q[aux].end(); it++ ){
            if( !vis[ *it ] )
                vis[ *it ] = true;
                c.push( *it );
        }
    }
}
 
int main(){
    grafo g(5);
    g.addConte( 0, 1 );
    g.addConte( 0, 4 );
    g.addConte( 1, 2 );
    g.addConte( 1, 3 );
    g.addConte( 1, 4 );
    g.addConte( 2, 3 );
    g.addConte( 3, 4 );
}