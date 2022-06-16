#include <iostream>

#define INPUT_GET cin >>
#define PRINT cout <<
#define BREAK_LINE << endl
#define PRINT_RESULT  factor << "x" \
        << i << " = " << i * factor

using namespace std;

void generate_multiplication_table(int factor){
	for(int i = 0; i <= 10; i++){
		PRINT
			PRINT_RESULT
		BREAK_LINE;
	}
}

int main(){
	int number_mult;

	INPUT_GET number_mult;

	generate_multiplication_table(
				number_mult
				);

	return 0;
}