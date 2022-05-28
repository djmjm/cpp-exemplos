#include <iostream>
#include "player.hpp"

using namespace std;

int main(){

	cout << *new Player << endl;
	cout << *new Player("Geromel") << endl;
	cout << *new Player("Kannemann", 
			 generate_attribute(90, 50, 10)) << endl;

	return 0;
}