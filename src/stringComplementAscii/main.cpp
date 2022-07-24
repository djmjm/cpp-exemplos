#include <iostream>

using namespace std;

#define ASCII_MAX 255

string string_complement_ascii(string origin){
    string complement = "";
    
    for(char index : origin){
        complement += 
            (char) abs(index - ASCII_MAX);
    }
    
    return complement;
}

int main(){
    cout << string_complement_ascii("Hello World ...") << endl;
    
    string aaa = "";
    
    aaa += (char) abs(65 - ASCII_MAX);
    aaa += (char) abs(65 - ASCII_MAX);
    aaa += (char) abs(65 - ASCII_MAX);
    
    cout << string_complement_ascii(aaa) << endl;
    
    cout << string_complement_ascii(
                string_complement_ascii(
                    "Hello World ..."
                )
            ) 
    << endl;

    return 0;
}
