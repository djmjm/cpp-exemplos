#include <iostream>

#define PRINT cout <<
#define BREAK_LINE << endl

using namespace std;

long long int calculate_factorial(long int n);

int main()
{
    int factorial_number = 20;
    PRINT 
        calculate_factorial(
                factorial_number
            )
    BREAK_LINE;

    return 0;
}

long long int calculate_factorial(long int n){
    if(n < 1){ return 0; };
    if(n == 1){ return 1; };
    
    return n * calculate_factorial(n-1);
}