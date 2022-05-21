#include <iostream>

using namespace std;

class Byte{
    private:
        char byte;
    public:
        Byte(){ byte = 'J'; }
        Byte(char c){ byte = c; }
        
        int sizeOf(){
            return sizeof(byte);
        }
        
        int kb(){
            return sizeOf() * 1024;
        }
        
        int mb(){
            return kb() * 1024;
        }
        
        long gb(){
            return mb() * 1024;
        }
        
        long tb(){
            return gb() * 1024;
        }
};

void printBytesConsole(Byte &c){
    cout << c.sizeOf() 
         << " Byte" 
         << endl;
         
    cout << c.kb() 
         << " Bytes == kByte" 
         << endl;
         
    cout << c.mb() 
         << " Bytes == megaByte" 
         << endl;
         
    cout << c.gb() 
         << " Bytes == gigaByte" 
         << endl;
         
    cout << c.tb() 
         << " Bytes == teraByte" 
         << endl;
}

int main(){
    
    Byte *c = new Byte();
    printBytesConsole(*c);
    
    return 0;
}
