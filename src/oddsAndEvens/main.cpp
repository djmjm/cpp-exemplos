#include <iostream>
#include <ostream>
#include <time.h>

#define RANDOMIZE srand(time(NULL))
#define CHOOSE_EVEN (rand() % 10) % 2 == 0;
#define CHOOSE_HAND rand() % 11

using namespace std;

class OddsAndEvens{
    private:
           int count_player1_wins = 0;
           int count_player2_wins = 0;
           
           string get_even(int even){
               if(even % 2 == 0) return "EVEN";
               else return "ODD";
           };
           
           void print_hand(
                             int player1,
                             int player2
                            ){
                cout << "PLAYER 1 HAND ->> "
                     << player1 << endl
                     << "PLAYER 2 HAND ->> "
                     << player2 << endl;                  
            }
            
            void print_result(int result){
                cout << "RESULT IS .... "
                     << result << " == "
                     << get_even(result);
            }
           
           void print_choices(int player1, 
                                int player2){
                cout << "PLAYER 1 CHOICE ->> "
                     << get_even(player1) << endl
                     << "PLAYER 2 CHOICE ->> "
                     << get_even(player2) << endl;
            };
           
           void print_game(){
               cout << "|| ODDS AND EVENS ||" 
                    << endl
                    << "--> NEW GAME <--" 
                    << endl
                    ;
           };
           
           void play(){
               bool hand1_choice = CHOOSE_EVEN;
               bool hand2_choice = !hand1_choice;
               
               int hand1_number = CHOOSE_HAND;
               int hand2_number = CHOOSE_HAND;
               
               int result = hand1_number +
                            hand2_number;
                            
               if(result % 2 == 0){
                   if(!hand1_choice){ count_player1_wins++; }
                   else{ count_player2_wins++; };
               }else{ 
                   if(hand1_choice){ count_player1_wins++; }
                   else{ count_player2_wins++; };
               };
               
               print_game();
               
               print_choices(
                          hand1_choice,
                          hand2_choice
                        );
                        
               print_hand(hand1_number,
                          hand2_number
                        );
                        
               print_result( result
                           );
           }
    
    public:
        OddsAndEvens(){
            RANDOMIZE;
            play();
        }
        friend ostream& operator << 
        ( ostream& out, const OddsAndEvens &game );
};

ostream& operator << ( ostream& out, const OddsAndEvens &game){
    out << endl;
    
    if(game.count_player2_wins
      > game.count_player1_wins
    ){ out << "PLAYER 2 WINS!!!!"; }
    else
     { out << "PLAYER 1 WINS!!!!"; }
        
    return out;
}

int main(){
    OddsAndEvens &new_game = *new OddsAndEvens();
    cout << new_game << endl;
    return 0;
}