#include <iostream>
#include <time.h>

#define RANDOMIZE srand( time( NULL ) )
#define BIT_SIZE 64
#define ___ for(;;)

using namespace std;

char choose_bit(){
    bool choose = 
        (bool) (rand() % 2);
        
    if(choose) { return '1'; }
    else { return '0'; }
}

string bits_random(int amount){
    string str_final = "";
    while(amount--){
        str_final += choose_bit();
    }
    
    return str_final;
}

int main(){
    
    RANDOMIZE;
    
    ___ cout << bits_random(BIT_SIZE) << endl;
    
    return 0;
}