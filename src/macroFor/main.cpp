#include <iostream>

using namespace std;

void joke(int one, int two, int three){ cout << "Hidden" << endl; }

#define for joke(1, 1, 1); for

int main(){
    
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            cout << "visible" << endl;
        };
    };

    return 0;
}
