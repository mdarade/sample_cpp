#include <iostream>
#include <vector>
#include <array>

using namespace std;


typedef struct x {
	int a;
	vector<array<uint64_t, 2>> v;	
}x_t;


class abc {
	public:
		abc() : x_obj({0}) {}
		~abc() {}

		x_t x_obj;
};


void f1() {
	if (1) {
		abc obj;
		obj.x_obj.v.push_back({1,2});
		cout << obj.x_obj.v.size() << std::endl;
	}
}


int main() {
	f1();
	return 0;
}

