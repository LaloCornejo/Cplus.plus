#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main() {
    char text_array[100];

    cin.getline(text_array, 100);

    int index = strlen(text_array) - 1;

    if(text_array[index] == 'y' && text_array[index-1] != 'a' && text_array[index-1] != 'e' && text_array[index-1] != 'i' && text_array[index-1] != 'u' && text_array[index-1] != 'u'){
        text_array[index] = 'i'; 
        text_array[index+1] = 'e'; 
        text_array[index+2] = 's'; 
    }else if (text_array[index] == 's'){
        text_array[index+1] = 'e'; 
        text_array[index+2] = 's'; 
    }else if (text_array[index] == 'h' && (text_array[index-1] == 's' || text_array[index-1] == 'c')){
        text_array[index+1] = 'e'; 
        text_array[index+2] = 's'; 
    }else{
        text_array[index+1] = 's';
    }

    for(int i=0; i < strlen(text_array); i++){
        cout << text_array[i];
    }
}