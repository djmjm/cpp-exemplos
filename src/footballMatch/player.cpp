#include "player.hpp"

Player::Player(){
	name = "Generic Player";

	skills.defence = 10;
	skills.support = 15;
	skills.attack = 90;
};

Player::Player(string name){
	this->name = name;

	skills.defence = 10;
	skills.support = 15;
	skills.attack = 90;
};

Player::Player(string name,
			atributes skills
		){
	this->name = name;
	this->skills = skills;
};

ostream &operator << (ostream &out, const Player &pl){

	string name = pl.name;
	for(auto &c : name){ c = to_lower_case(c); }

	out << " || " << 
		name
	    << " || " << endl
		<< " --> defense = " << pl.skills.defence << endl
		<< " --> support = " << pl.skills.support << endl
		<< " --> attack = "  << pl.skills.attack << endl;

	return out;
};

atributes generate_attribute(int defence,
							 int support,
							 int attack
							){
	atributes &answer = *(atributes*) malloc(SIZE_ATTR);

	answer.defence = defence;
	answer.support = support;
	answer.attack = attack;

	return answer;
}