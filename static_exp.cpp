#include <iostream>
using namespace std;

class statica {
public:
    static int set(int delay);
    static int get();
	static int k;
};

int statica::set(int delay) {
	statica::k = delay;
}

int statica::get() {
	return statica::k;
}

int statica::k;

int main() {
	//statica obj1;
	//obj1.set(10);
	statica::set(10);
	cout << "it is " << statica::get() << endl;
	return 0;
}
