#include <iostream>
#include <thread>

using namespace std;

#define NUM_THREADS 10

double x;
double y;
double z;

void foo(int id){
    x = id;
}

void bar(int id){
    y = id;
}

void delta(int id){
    z = id;
}

int main(){
    x = 1;
    y = 0;
    z = 0;
    
    thread *threads = (thread*) malloc(sizeof(thread) * NUM_THREADS);
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i] = thread(foo, i);
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i].join();
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i] = thread(bar, i);
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i].join();
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i] = thread(delta, i);
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i].join();
    }
    
	cout << (x / z) * y * (y / z) * x<< endl;

	return 0;
}