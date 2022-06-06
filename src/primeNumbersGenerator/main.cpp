#include <iostream>
#include <stdlib.h>

#define NUMBER_SIZE sizeof(number)

#define NEW_LIST \
(number *) malloc(n_numbers * NUMBER_SIZE)

#define LIST_NUMBER number*


using namespace std;

struct number {
	int value;
	bool prime = false;
};

LIST_NUMBER generate_primes();
void print_list(LIST_NUMBER list);

int n_numbers = 1000;

int main(){
	
	LIST_NUMBER list_primes = generate_primes();
	print_list(list_primes);
	
	return 0;
}

LIST_NUMBER generate_primes(){
	LIST_NUMBER list_numbers = NEW_LIST;
	
	for(int i = 2; i < n_numbers; i++){
		list_numbers[i].value = i;
		
		int index = i;
		bool find_factor = false;
		while(--index > 1){
			if(i % index == 0){
				find_factor = true;
			}
		}
		if(!find_factor){
			list_numbers[i].prime = true;
		}
	}
	
	return list_numbers;
}

void print_list(LIST_NUMBER list){
	int number = 0;
	
	for(int i = 0; i < n_numbers; i++){
		if(list[i].prime){
			number++;
			cout << "list["
				 << number
				 << "] = "
				 << list[i].value 
				 << endl;
		}
	}
	
	cout << "NUMERO TOTAL -->> " 
		 << number
		 << endl;
}
