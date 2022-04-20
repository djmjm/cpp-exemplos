#include <iostream>

using namespace std;

int main(){

	char words[7];
	words[6] = '\0';

	for(int i = 0; i < 25; i++){
		words[0] = i + 65; 
		for(int j = 0; j < 25; j++){
			words[1] = j + 65; 
			for(int x = 0; x < 25; x++){
				words[2] = x + 65; 
				for(int y = 0; y < 25; y++){
					words[3] = x + 65; 
					for(int m = 0; m < 25; m++){
						words[4] = m + 65;
						for(int f = 0; f < 25; f++){
							words[5] = f + 65;
							cout << words << endl;
						}
					}
				}
			}
		}
	}

	return 0;
}