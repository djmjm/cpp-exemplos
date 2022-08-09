#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <time.h>
#include <chrono>
#include <mutex>

#define RANDOMIZE srand(time(NULL))
#define WAIT std::this_thread::sleep_for(std::chrono::milliseconds(x));

using namespace std;

string answer = "";
mutex copy_str;

void get_char_string
(string origin, int index){
    int x = rand() % 100; WAIT;

    while(x--);

    copy_str.lock();
        answer += origin.at(index);
    copy_str.unlock();
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
