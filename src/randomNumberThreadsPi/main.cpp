#include <stdio.h>
#include <thread>

#include <iostream>
#include <sstream> 

#include <cmath>

#define RANGE 1024
#define PI 3.14159265
#define RANDOMIZE srand(get_final_seed(seed_final))
#define GENERATE_INTEGER (unsigned long int) \
		( generator * pow(10, 50) ) % RANGE

using namespace std;

unsigned long int seed = 0;
string seed_final = "";

void generate_seed(int number);
string integer_to_string(unsigned long int number);
long double get_final_seed(string seed_final){
	long double answer = 0;
	for(char number: seed_final){
		int integer = int(number);
		answer += integer / (integer * pow(10, integer) );
		answer *= PI;
	}
	return answer;
}

int main(){
	
	cout << endl;

	thread t_1 (generate_seed, 1);
	thread t_2 (generate_seed, 2);
	thread t_3 (generate_seed, 3);
	thread t_4 (generate_seed, 4);
	thread t_5 (generate_seed, 5);
	thread t_6 (generate_seed, 6);
	thread t_7 (generate_seed, 7);
	thread t_8 (generate_seed, 8);
	thread t_9 (generate_seed, 9);

	t_1.join();
	t_2.join();
	t_3.join();
	t_4.join();
	t_5.join();
	t_6.join();
	t_7.join();
	t_8.join();
	t_9.join();

	auto generator = get_final_seed(seed_final);

	cout << "|SEED GENERATED ->>" << endl
	     <<  generator << endl;

	//RANDOMIZE;

	cout << "|RANDOM NUMBER GENERATE ->>" << endl
		 << GENERATE_INTEGER << endl;

	return 0;
}

void generate_seed(int number){
	unsigned long int decimal_places = seed / 10;
	seed += number * pow(10, decimal_places);
	seed /= PI / number;
	seed_final += integer_to_string(seed);
}

string integer_to_string(unsigned long int number){ 
	stringstream ss;  
	ss << number;  
	string s;  
	ss >> s;  
	return s;
}