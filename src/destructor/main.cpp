#include <iostream>

using namespace std;

class DestructorExample{
	public:
		int *pointer;

		DestructorExample(){
			pointer = (int *) 1111;
		};

		~DestructorExample(){
			pointer = (int *) 2222;;
		}

};

int main(){

	auto destruct = new DestructorExample();
	cout << destruct->pointer << endl;

	delete destruct;
	cout << destruct->pointer << endl;

	return 0;
}