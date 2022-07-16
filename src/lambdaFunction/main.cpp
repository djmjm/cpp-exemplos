#include <iostream>

using namespace std;

auto _integer = []{ return 9999; } ;
auto _boolean = []{ return true; } ;
auto _string = []{ return "string"; } ;
auto _char = []{ return 'c'; } ;
auto _double = []{ return 3.14159265; } ;

int main(){
	
	int my_int = _integer();
	bool my_bool = _boolean();
	string my_str = _string();
	char my_chr = _char();
	double my_dbl = _double();
	
	cout << my_int << endl;
	cout << my_bool << endl;
	cout << my_str << endl;
	cout << my_chr << endl;
	cout << my_dbl << endl;
	
	return 0;
}