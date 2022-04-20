#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>


using namespace std;

string fixFormat(unsigned int param);
string integerToString(unsigned int param);
int getNumberFixDigit(unsigned int param);

int main(){
	unsigned int digits = 0;

	ofstream txt;
  	txt.open ("allDigits.txt");

	for( digits = 0; digits <= 999999; digits++)
		txt << fixFormat(digits) << endl;

	txt.close();

	return 0;
}

string fixFormat(unsigned int param){
	if(param < 10){
		return "00000" + integerToString(param);
	} else if(param < 100){
		return "0000" + integerToString(param);
	} else if(param < 1000){
		return "000" + integerToString(param);
	} else if(param < 10000){
		return "00" + integerToString(param);
	}else if(param < 100000){
		return "0" + integerToString(param);
	}else{
		return integerToString(param);
	}
}


string integerToString(unsigned int param){ 
	stringstream ss;  
	ss << param;  
	string s;  
	ss >> s;  
	return s;
}