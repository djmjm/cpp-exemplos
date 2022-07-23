#include <iostream>
#include <string>
#include <stack>

using namespace std;

string check_value( unsigned long int toma_essa){
    string answer = "";
    while(toma_essa > 0){
        answer += (char) ( toma_essa - (toma_essa/100) * 100 ) ;
        toma_essa /= 100;
    }
    ;
    return reverse_string(answer);
}

int main(){
    
    string answer = check_value(7879678269796978);
    
    cout << check_value(7879678269796978) << endl;
    cout << check_value(766583668285746583) << endl;
    cout << check_value(80698279818569) << endl;
    cout << check_value(7265894472658933) << endl;
    
    
    return 0;
}