#include <iostream>

using namespace std;

class sample {
	public:
	sample() {}
	~sample() {}

	void print() {
		cout << __func__ << ":" << var1 << std::endl;
	}

	public:
		static int var1;
		int var2;
};

int sample::var1 = 0;

int main() {

	sample obj;

	cout << "1:" << sample::var1 << std::endl;
	//sample::print();
	obj.print();
	cout << "2:" << obj.var2 << std::endl;

	return 0;
}

