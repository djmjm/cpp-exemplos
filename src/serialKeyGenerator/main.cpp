#include <iostream>
#include <time.h>

#define RANDOMIZE srand(time(NULL))


using namespace std;

string generate_key();
char get_letter();
char get_number();

int main()
{
    RANDOMIZE;
    cout << generate_key();

    return 0;
}

string generate_key(){
    string &key = *(new string());
    
    for(int i = 1; i <= 16; i++){
        if(i % 6 == 0) { key += '-'; }
        bool genNumber = !(0 + rand() % 3);
        if(genNumber){ key += get_number(); }
        else{ key += get_letter(); }
    }
    
    return key;
}

char get_letter(){
    return (char) 'A' + rand() % 24;
}

char get_number(){
    return (char) '0' + rand() % 10;
}