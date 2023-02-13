#include <iostream>
using namespace std;

class A { 
	friend class B;
	protected:
		int a_ = 10;
};

class B {
	public:
		void print(A a) {
			cout << a.a_;
		}
	public:
		int b_ = 20;
	
};

int main() {
	A a_obj;
	B b_obj;

	b_obj.print(a_obj);

	return 0;
}

	

