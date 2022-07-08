#include <iostream>

using namespace std;

string itoa(int number){
    
    string answer = "";
     while(number > 0){
        int ok = number - (number/10)*10;
        string add = "";
        add += (char) 48 + ok ;
        answer.insert( 0, add );
        number /= 10;
    }
    
    return answer;
}
;

int main(){
    int number = 123456789;
    string answer = itoa( number );
    
    cout << answer << endl;
    
    for( char add = '0'; add != '9'; add++){
        answer += add;
        cout << answer << endl;
    }
    
    return 0;
}