#include <iostream>

using namespace std;

int main(){
   int iter = 10;
   for(int i = 0; i < --iter;) { cout << iter << endl; } 
   iter = 10; cout << endl;
   
   for(int i = 0; i < iter--;) { cout << iter << endl; }
   cout << endl;
}
