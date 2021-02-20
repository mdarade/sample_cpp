#include <iostream>

using namespace std;

void f1() {
	int *a = new int[5];
	cout << "hello world" << endl;
}

int main() {
	f1();

	cout << "abt to sleep" << endl;
	while(1);
	return 0;
}
