#include <iostream>
#include <time.h>

using namespace std;

int deterministic();
int nonDeterministic();

int main(){

	cout << "DETERMINISTICO ->> " << deterministic() << endl;
	cout << "NÃO DETERMINISTICO ->> " << nonDeterministic() << endl;
	
	return 0;
}

int deterministic(){
	return 1;
}

int nonDeterministic(){
	srand(time(
		NULL
		)
	);
	return rand() % 1024;
}