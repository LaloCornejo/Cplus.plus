#include<iostream>
#include<queue>
using namespace std;

class nodo{
public:
    int data;
    nodo *left;
    nodo *right;
    nodo(int);
};

nodo::nodo(int d){
    data = d;
    left = NULL;
    right = NULL;
}

void Pre(nodo *r){
    if(r == NULL)
        return;
    cout << r-> data << " ";
    Pre(r->left);
    Pre(r->right);
}

void Post(nodo *r){
    if( r == NULL )
        return;
    Post(r->left);
    cout << r-> data << " ";
    Post(r-> right);
}

void Ino(nodo* r){
    if( r == NULL )
        return;
    Ino(r->left);
    Ino(r->right);
    cout << r->data << " ";
}

void amplitud( nodo* r ){
    queue<nodo*> q;
    if ( r == NULL )
        return;
    if( r != NULL )
        q.push( r );
    while( !q.empty() ){
        nodo* aux = q.front();
        cout << aux->data << " ";
        q.pop();
        if( aux->left != NULL )
            q.push( aux->left );
        if( aux->right != NULL )
            q.push( aux->right ); 
    }
}

int main(){
    nodo* root = new nodo(1);

    root->left = new nodo(2);
    root->right = new nodo(3);

    root->left->left = new nodo(4);
    root->left->right = new nodo(5);

    printf("** Recorrido Preorden **\n");
    Pre( root );
    cout << "\n";
    printf("** Recorrido Postorden **\n");
    Post( root);
    cout << "\n";
    printf("** Recorrido Inorden **\n");
    Ino( root );
    cout << "\n";
    printf( "** Recorrido por amplitud **\n" );
    amplitud( root );
}