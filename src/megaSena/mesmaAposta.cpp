#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool checkGanhou(int *aposta, int *sorteio){
	for(int i = 0; i < 6; i++)
		if(aposta[i] != sorteio[i])
			return false;

	return true;
}

void sort(int *sorteio){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(sorteio[i] < sorteio[j]){
				int aux = sorteio[i];
				sorteio[i] = sorteio[j];
				sorteio[j] = aux;
			}
		}
	}
}

int main(){

	int aposta[6];

	aposta[0] = 5;
	aposta[1] = 13;
	aposta[2] = 18;
	aposta[3] = 23;
	aposta[4] = 37;
	aposta[5] = 53;

	bool ganhou = false;
	int sorteio[6];
	long int numero_tentativas = 0;
	srand(time(NULL));

	while(!ganhou){

	sorteio[0] = (int)(rand() % 60) + 1;
	sorteio[1] = (int)(rand() % 60) + 1;
	sorteio[2] = (int)(rand() % 60) + 1;
	sorteio[3] = (int)(rand() % 60) + 1;
	sorteio[4] = (int)(rand() % 60) + 1;
	sorteio[5] = (int)(rand() % 60) + 1;
	sort(sorteio);

	cout << sorteio[0] << " - "  <<
			sorteio[1] << " - " <<
			sorteio[2] << " - " <<
			sorteio[3] << " - " <<
			sorteio[4] << " - " <<
			sorteio[5]
		<< endl;
	ganhou = checkGanhou(sorteio, aposta);
	numero_tentativas++;

	}

	cout << "Você ganhou com " << numero_tentativas
			<< " tentativas ..."
		<< endl;

	return 0;
}