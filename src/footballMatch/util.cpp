#include "util.hpp"

char to_lower_case(char c){
	bool question = c >= 97 
				  &&
				  c <= 122;

	if(question) return c - 32;
	else return c;
}