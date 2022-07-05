#include <iostream>
#include <time.h>

#define RANDOMIZE srand(time(NULL))

using namespace std;

enum result{
    HEAD, TAIL
};

class CoinToss{
    private:
        result winner;
    public: 
        CoinToss(){
            RANDOMIZE;
            bool choice =
                (bool) (rand() % 2);
            
            if(choice){ winner = result::HEAD; }
            else { winner = result::TAIL; }
            ;
            print_result();
        }
        
         CoinToss(int n_games){
             
            int head_victory = 0;
            int tail_victory = 0;
            RANDOMIZE;
            
            while(n_games-- > 0){
                bool choice =
                    (bool) (rand() % 2);
                
                if(choice){ 
                    winner = result::HEAD; 
                    head_victory++;
                }
                else { 
                    winner = result::TAIL; 
                    tail_victory++;
                }
                ;
                print_result();
            }
            
            cout << head_victory << " head victory ..."
                 << endl
                 << tail_victory << " tail victory ..."
                 ;
        }
        
        void print_result(){
            if (winner == result::HEAD){
               cout << "HEAD" << endl;
            }
            else{
               cout << "TAIL" << endl;
            }
        }
};

int main(){
    
    new CoinToss(100);

    return 0;
}
