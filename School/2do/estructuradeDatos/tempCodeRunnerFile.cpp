#include<iostream>
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
    cout << r->data << "\n";
}

int main(){
    nodo* root = new nodo(1);

    root->left = new nodo(2);
    root->right = new nodo(3);

    root->left->left = new nodo(4);
    root->left->right = new nodo(5);

    printf("** Recorrido Preorden **\n");
    Pre( root );
    printf("** Recorrido Postorden **\n");
    Post( root);
    printf("** Recorrido Inorden **\n");
    Ino(  root);
}