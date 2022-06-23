#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool check_palindrome(string word){
    stack<char> last_sort;
	queue<char> first_sort;
	
	for(char letter: word){
	    last_sort.push(letter);
	    first_sort.push(letter);
	}
	
	bool is_empty = 
	                last_sort.empty()
	                &&
	                first_sort.empty()
	                ;
	
	while(!is_empty){
	    bool not_equal = last_sort.top()
	                     !=
	                     first_sort.front();
	   
	   if(not_equal){
	       return false;
	   }
	   else{
	       last_sort.pop();
	       first_sort.pop();
	       is_empty = 
	                last_sort.empty()
	                &&
	                first_sort.empty()
	                ;
	   }
	}
	
	return true;
}

int main(){
    
    cout << check_palindrome("boi") << endl;
    cout << check_palindrome("arara") << endl;
    cout << check_palindrome("computador") << endl;
    cout << check_palindrome("racecar") << endl;
    cout << check_palindrome("gremio") << endl;
    cout << check_palindrome("subinoonibus") << endl;
    
    return 0;
}