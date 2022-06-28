#include <iostream>
#include <math.h>

using namespace std;

#define PRINT cout <<
#define BREAK_LINE << endl

void print_recursive(int param){
    PRINT
        param
    BREAK_LINE;
    
    if(param == 0){ return; }
    else{ print_recursive( --param ); };
    
}

int atoi_custom( string str ){
    
    int final_number = 0;
    
    for( char chr : str){
        int temp_number =
            (int) chr - 48;
        final_number *= 10;
        final_number += temp_number;
    }
    return final_number;
}

int main(){
    
    print_recursive( atoi_custom( "14879" ) );
    
    return 0;
}