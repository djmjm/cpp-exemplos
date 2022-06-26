#include <iostream>

using namespace std;

#define PRINT cout <<
#define BREAK_LINE << endl

#define FOR_ONE for(char one = '0'; one <= '9'; one++){
#define FOR_TWO for(char two = '0'; two <= '9'; two++){
#define FOR_THREE for(char three = '0'; three <= '9'; three++){
#define FOR_FOUR for(char four = '0'; four <= '9'; four++){
#define FOR_FIVE for(char five = '0'; five <= '9'; five++){
#define FOR_SIX for(char six = '0'; six <= '9'; six++){

#define END_FOR }

long unsigned int find_password(const char *password){
    
    long unsigned int
        attempts = 0;
    
    FOR_SIX
    FOR_FIVE
    FOR_FOUR
    FOR_THREE
    FOR_TWO
    FOR_ONE
    
        attempts++;
    
        bool found = password[0] == one
                     &&
                     password[1] == two
                     &&
                     password[2] == three
                     &&
                     password[3] == four
                     &&
                     password[4] == five
                     &&
                     password[5] == six
                     ;
                     
        if(found){
            return attempts;
        }
                            
    END_FOR
    END_FOR
    END_FOR
    END_FOR
    END_FOR
    END_FOR
    
    return false;
}

int main()
{
    char password[6];
    
    password[0] = '0';
    password[1] = '3';
    password[2] = '9';
    password[3] = '0';
    password[4] = '1';
    password[5] = '4';
    
    long unsigned int 
        attempts =
            find_password(password);
    
    PRINT "Password ->> ";
    PRINT password[0];
    PRINT password[1];
    PRINT password[2];
    PRINT password[3];
    PRINT password[4];
    PRINT password[5]
    BREAK_LINE;
    
    if(attempts){
        PRINT "found!" BREAK_LINE;
        PRINT attempts;
        PRINT " iterations ... " BREAK_LINE;
    }else{
        PRINT "not found!" BREAK_LINE;
    }
    return 0;
}