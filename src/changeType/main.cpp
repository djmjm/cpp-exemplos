#include <iostream>

using namespace std;

auto _my_string = []{ return "okokok"; };

auto _my_function = []{ 
    return _my_string();
} ;

 void* change_type(){
    int size = sizeof( _my_function() );
    char *answer = (char*) malloc(size);
    answer = (char*) _my_function();
    
    void *result = (void*) answer;
    
    return result;
}

int main()
{
    cout << (char *) change_type() << endl;
    
    return 0;
}
