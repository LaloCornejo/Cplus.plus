// Author: L Æ L Ö

#include<iostream>
using namespace std;

bool has_duplicates(int[], int);

int main(){
    int n;
    cin >> n;
    int nums[n];

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int has = has_duplicates( nums, n);

    if(has){
        cout << "Hay duplicados" << endl;
    }else{
        cout << "No hay duplicados" << endl;
    }

    return 0;
}

bool has_duplicates(int nums[], int n){
    bool has = false;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(nums[i] == nums[j]){
                has = true;
                break;
            }
        }
    }
    return has;
}

/*
El programa que revisa es mega bruto :)
*/