#include <iostream>

using namespace std;

void printConsole(int value);
void printConsole(string value);

void findAllPossibleSums(int maxDigit, int goal);
void printNotFoundConsole();
string printFound(int *digits);

int main(int argc, char** argv) {
	int const MAX_DIGIT = 9;
	int const SUM_GOAL = 9;
	
	printConsole("-- MAX DIGIT --");
	printConsole(MAX_DIGIT);
	printConsole("-- SUM GOAL --");
	printConsole(SUM_GOAL);
	
	printConsole("-- RESULTS --");
	findAllPossibleSums(MAX_DIGIT, SUM_GOAL);
	
	return 0;
}

void printConsole(string value){
	cout << value << endl;
}

void printConsole(int value){
	cout << value << endl;
}

void printFoundConsole(int *digits, int goal){
	cout << digits[0] << " + " 
		 <<	digits[1] << " + "
		 <<	digits[2] << " + "
		 <<	digits[3] << " = "
		 <<	goal 	  << endl;
}

void printNotFoundConsole(){
	cout << "No possible sum found!" << endl;
}

void findAllPossibleSums(int maxDigit, int goal){
	
	bool foundOne = false;
	int numberSums = 0;
	
	for(int i = 0; i < maxDigit; i++){
		for(int j = 0; j < maxDigit; j++){
			for(int n = 0; n < maxDigit; n++){
				for(int m = 0; m < maxDigit; m++){
					bool found = i + j + n + m == goal;
					int digits[4] = {i, j, n, m};
					
					if(found) { 
						printFoundConsole(digits, goal);
						if(!foundOne) { foundOne = true; }
						numberSums++;
					}
					
				}
			}
		}
	}
	
	if(!foundOne) { printNotFoundConsole(); }
	else{
		printConsole("-- Number sums found --");
		printConsole(numberSums);
	}
	
}
