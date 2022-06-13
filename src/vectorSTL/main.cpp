#include <iostream>
#include <vector>

#define PRINT cout << 
#define BREAK_LINE << endl
#define CUT_LINE << "*****************"

using namespace std;

int main(){

	vector<string> names;

	names.push_back("MARIA");
	names.push_back("PEDRO");
	names.push_back("JOAO");
	names.push_back("OLYX");
	names.push_back("PAWEL");

	vector<string> last_names;

	last_names.push_back("ARIAS");
	last_names.push_back("NAVARRO");
	last_names.push_back("EDWARDS");
	last_names.push_back("JARVIS");
	last_names.push_back("BRADY");


	int print_times = 2;

	while(print_times > 0){

		for(auto name : names){
			PRINT "" BREAK_LINE;

			PRINT  	(string)
					(print_times > 1 
							? 
							"|| Name --> "
							:
							"|| Last Name --> "
							
					);
			PRINT name
				  
				  BREAK_LINE
				  CUT_LINE 

				  ;
		}

		names.swap(last_names);

		--print_times;
	}

	return 0;
}