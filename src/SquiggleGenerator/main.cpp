#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

#define MIN_WIDTH 0
#define MIN_HEIGHT 0
#define MAX_WIDTH 100
#define MAX_HEIGHT 10
#define WAIT std::this_thread::sleep_for(std::chrono::milliseconds(3000));

#define RANDOMIZE srand(time(NULL))

struct position{
    int x;
    int y;
}
;

enum type{
    marked = 1, blank = 0
}
;

enum movements{
    left = 0, right = 1, up = 2, down = 3
}
;

class Squiggle{
    
    private:
    position pos;
    type map[MAX_WIDTH][MAX_HEIGHT] = { (type)0};
    
    void moving(movements movement){
        switch(movement){
            case movements::left: pos.x--; return;
            case movements::right: pos.x++; return;
            case movements::up: pos.y--; return;
            case movements::down: pos.y++; return;
        }
    }
    
    bool is_outside(){
        bool left = pos.x < 0;
        bool right = pos.x > MAX_WIDTH;
        bool up = pos.y < 0;
        bool down = pos.y > MAX_HEIGHT;
        
        return left || right || up || down;
    }
    
    void generate(){
        if(is_outside()){ return; }
        int x = pos.x;
        int y = pos.y;
        
        map[x][y] = type::marked;
        
        movements move = (movements) (rand() % 4);
        
        moving(move); generate();
        
    }
    
    public: 
    Squiggle(){
        
        RANDOMIZE;
        
        pos.x = rand() % MAX_WIDTH;
        pos.y = rand() % MAX_HEIGHT;
        
        generate();
        
        for(int j = MIN_HEIGHT; j < MAX_HEIGHT; j++){
            for(int i = MIN_WIDTH; i < MAX_WIDTH; i++){
                if(map[i][j] == type::marked){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    while(true){
        delete(new Squiggle());
        WAIT;
    }
    return 0;
}
