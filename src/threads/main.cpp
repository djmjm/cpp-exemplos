#include <iostream>
#include <thread>

using namespace std;

void foo(int id){
	cout << id << endl;
}

int main(){

	thread first_t (foo, 1);
	thread second_t (foo, 2);
	thread third_t (foo, 3);
	thread fourth_t (foo, 4);
	thread fifth_t (foo, 5);

	first_t.join();
	second_t.join();
	third_t.join();
	fourth_t.join();
	fifth_t.join();

	return 0;
}