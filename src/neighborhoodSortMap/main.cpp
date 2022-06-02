#include "map.hpp"

int main(){

	for(int i = 0; i < 6; i++){
		cout << "______________________________________________________" << endl << endl;

		Map &map = *new Map(i);

		cout << " |STARTED MAP " << map << endl;

		map.sort();

		cout << " |SORTED RANGE:" << i  << map << endl;

		delete(&map);

		cout << "______________________________________________________" << endl << endl;
	}

	return 0;
}