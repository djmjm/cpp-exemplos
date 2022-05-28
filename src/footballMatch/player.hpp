#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "util.hpp"

#define SIZE_ATTR 12

using namespace std;

struct atributes{
	int defence;
	int support;
	int attack;
};

class Player{
	public: Player(void);
			Player(string name);
			Player(string name, atributes skills);

			int *get_all_atributes();
			string name;

	friend ostream &operator << (ostream &out, const Player &pl);

	private: atributes skills;
			 int *skillsVector = (int*) malloc(SIZE_ATTR);

};

atributes generate_attribute(int defence, int support,
							 int attack);

#endif