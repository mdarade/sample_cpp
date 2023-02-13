#include <iostream>
using namespace std;

class A {
public:
	A(int& a) {}
	void print() {
		cout << a << std::endl;
	}
	//int a_;
};


int main() {
	int a = 10;
	A obj(a);
	obj.print();
	//cout << obj.a << std::endl;	
	return 0;
}
