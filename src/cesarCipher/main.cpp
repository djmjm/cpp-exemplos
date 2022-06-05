#include <iostream>

using namespace std;

class Cipher{
    private:
        short int shift_key;
    public:
        Cipher(){
            shift_key = 3;
        };
        Cipher(int shift_key){
            this->shift_key = 
                    shift_key % 26;
        };
        
        string encrypt(string text){
            string answer = "";
            
            for(auto letter : text){
                answer += letter + shift_key;
            }
            
            return answer;
        }
        
        string decrypt(string text){
            string answer = "";
            
            for(auto letter : text){
                answer += letter - shift_key;
            }
            
            return answer;
        }
};

int main(){
    Cipher &cipher_default = *new Cipher();
    
    cout << "IMORTAL" << endl
         << cipher_default.encrypt("IMORTAL") 
         << endl
         << cipher_default.decrypt(
                cipher_default.
                encrypt("IMORTAL") 
            )
         << endl;
         
    delete(&cipher_default);
    
    Cipher &cipher_24 = *new Cipher(24);
    
    cout << "IMORTAL" << endl
         << cipher_24.encrypt("IMORTAL") 
         << endl
         << cipher_24.decrypt(
                cipher_24.
                encrypt("IMORTAL") 
            )
         << endl;
         
    delete(&cipher_24);
    
    return 0;
}