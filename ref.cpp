#include <iostream>
//using namespace std;

void fn2(int& i) {
	cout << i << endl;
	i=30;
	cout << i << endl;
}


void fn1(int& i) {
	cout << i << endl;
	i=20;
	cout << i << endl;
	fn2(i);
	cout << i << endl;

}

int main() {
	int i=10;
	fn1(i);
	cout << i << endl;
	return 0;
}

