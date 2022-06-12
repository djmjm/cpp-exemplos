#include <iostream>
#include <stdlib.h>

#define INT_SIZE 4

using namespace std;

int main(){
    
    int *memory_pointer = (int*) malloc(INT_SIZE * 3);
    int *vector = memory_pointer;
    
    *memory_pointer = 1983; memory_pointer++;
    *memory_pointer = 1995; memory_pointer++;
    *memory_pointer = 2017;
    
    for(int i = 0; i < 3; i++){
        cout << vector[i] << endl;
    }
    
    for(int i = 0; i < 3; i++){
        *memory_pointer -= 1;
        memory_pointer--;
    }
    
    for(int i = 0; i < 3; i++){
        cout << vector[i] << endl;
    }
    
    
    return 0;
}