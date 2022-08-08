#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <time.h>
#include <chrono>

#define RANDOMIZE srand(time(NULL))
#define WAIT std::this_thread::sleep_for(std::chrono::milliseconds(x));

using namespace std;

string answer = "";

void get_char_string
(string origin, int index){
    int x = rand() % 100; WAIT;
    
    while(x--);
    
    answer += origin.at(index);
}
;

int main(){
    
    RANDOMIZE;
    
    string origin;
    
    cout << "Digite uma palavra ...." << endl;
    cin >> origin;
    
    int num_thread = origin.length();
    
    thread threads[num_thread];
    
    for(int i = 0; i < num_thread; i++){
        threads[i] = thread(get_char_string, origin, i);
    }
    
    for(int i = 0; i < num_thread; i++){
        threads[i].join();
    }
    
    cout << answer << endl;
    
    return 0;
}