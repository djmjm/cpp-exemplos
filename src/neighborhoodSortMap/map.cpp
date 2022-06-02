#include "map.hpp"

Map::Map(){
	RANDOMIZE;
	for(int i = MIN; i < MAX; i++){
		for(int j = MIN; j < MAX; j++){
			positions[i][j] = 
				(type) (rand() % 5);
		}
	}
}

Map::Map(int range){
	RANDOMIZE;
	this->range = range;
	for(int i = MIN; i < MAX; i++){
		for(int j = MIN; j < MAX; j++){
			positions[i][j] = 
				(type) (rand() % 5);
		}
	}
}

void Map::sort(){
	if(range < 1){ return; }

	type temp_positions[MAX][MAX] = { one };

	for(int i = MIN; i < MAX; i++){
		for(int j = MIN; j < MAX; j++){
			temp_positions[i][j] = check_adjs(i, j);
		}
	}

	for(int i = MIN; i < MAX; i++){
		for(int j = MIN; j < MAX; j++){
			positions[i][j] = temp_positions[i][j];
		}
	}
};

type Map::check_adjs(int x, int y){
	int count[5] = { 0 };
	int result = 0;

	for(int i = x - range; i < x + range; i++){
		for(int j = y - range; j < y + range; j++){
			if( check_bound(i, j) ){
				if(i == x && j == y){continue;};
				count[ positions[i][j] ]++;
				//cout << positions[i][j] << endl;
			}
		}
	}

	for(int i = 0; i < 5; i++){
		if(result < count[i]){ 
			result = i;
		};
	}

	return (type) result;
}

bool Map::check_bound(int x, int y){
	return  (x >= MIN) && (x < MAX)
		     &&
		    (y >= MIN) && (y < MAX)
		    ;
}

ostream& operator << ( ostream &out, type type_value ){
	switch (type_value){
		case type::one : out << " || "; break;
		case type::two : out << " ** "; break;
		case type::three : out << " == "; break;
		case type::four : out << " jj "; break;
		case type::five : out << " cc "; break;
	}

	return out;
}

ostream& operator << ( ostream &out, const Map &map ){
	
	out << " | CURRENT MAP >>>>>" << endl
		<< " -------------------" << endl;

	for(int i = MIN; i < MAX; i++){
		for(int j = MIN; j < MAX; j++){
			out << map.positions[i][j];
		}
		out << endl;
	}

	return out;
};

