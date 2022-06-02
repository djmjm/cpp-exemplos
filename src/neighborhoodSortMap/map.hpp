#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include <ostream>

#include <time.h>

#define RANDOMIZE srand(time(NULL))
#define MAX 10
#define MIN 0
#define RANGE 2

using namespace std;

enum type{
	one = 1, two = 2, 
	three = 3, four = 4, 
	five = 0
};

class Map{
	private:
		int range = RANGE;
		type positions[MAX][MAX];
		type check_adjs(int x, int y);
		bool check_bound(int x, int y);

	public:
		 Map();
		 Map(int range);
		 void sort();

		 friend ostream& operator << ( ostream &out, const Map &map );
};

#endif