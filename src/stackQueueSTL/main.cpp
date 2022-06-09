#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	
	stack<int> stack;
	queue<int> queue;

	for(int i = 0; i < 10; i++){
		stack.push(i);
		queue.push(i);
	}

	while(!stack.empty()){
		cout << stack.top() << endl;
		stack.pop();
	}

	while(!queue.empty()){
		cout << queue.front() << endl;
		queue.pop();
	}

	return 0;
}