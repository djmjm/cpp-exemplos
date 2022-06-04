#include <iostream>
#include <ostream>
#include <stdlib.h>

#define TYPE long long int
#define SIZE_INT sizeof(TYPE)
#define SIZE_SEQUENCE (SIZE_INT * iterations)
#define NEW_SEQUENCE (TYPE*) malloc(SIZE_SEQUENCE)

using namespace std;

class Fibonacci{
    private: 
        long long int previous, next, iterations;
        long long int *sequence;
        bool default_sequence = true;
        
        void generate_sequence(){
            for(int i = 0; i < iterations; i++){
                sequence[i] = previous;
                
                auto temp = next;
                next += previous;
                previous = temp;
            }
        }
        
    public: 
        Fibonacci(){
            previous = 0;
            next = 1;
            iterations = 10;
            sequence = NEW_SEQUENCE;
            
            generate_sequence();
        }
        
        Fibonacci(int iterations){
            previous = 0;
            next = 1;
            this->iterations = iterations;
            sequence = NEW_SEQUENCE;
            
            generate_sequence();
        }
        
        Fibonacci(int previous, int next,
                  int iterations
                  ){
            this->previous = previous;
            this->next = next;
            this->iterations = iterations;
            sequence = NEW_SEQUENCE;
            
            default_sequence = false;
            
            generate_sequence();
        }
        
        friend ostream& operator << 
            (ostream &out, const Fibonacci &Fibonacci);
        
};

ostream& operator << (ostream &out, const Fibonacci &fibonacci){
    if(fibonacci.default_sequence){
        out << "|| DEFAULT SEQUENCE ||"   << endl;
    }else{
        out << "|| CUSTOM SEQUENCE ||"   << endl;
    }
    
    out << "Iterations number ->> "
        << fibonacci.iterations << endl << endl
        << "<< -- SEQUENCE GENERATED -- >>" << endl;
        
    for(int i = 0; i < fibonacci.iterations; i++){
        out << "|  Position[" << (i+1) << "] ->> "
            << fibonacci.sequence[i] << endl;
    }
        
    return out << endl << endl;
}


int main(){
    
    cout << *new Fibonacci() << endl;
    cout << *new Fibonacci(50) << endl;
    cout << *new Fibonacci(10, 11, 50) << endl;
    
    return 0;
}