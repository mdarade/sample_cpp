#include <iostream>
#include <memory>

using namespace std;

struct basic {
	basic(int num) : val(num) {}
	int val;
};

int main() {
	basic obj_1(10);
	auto basic_x = make_shared<basic>(10);
	auto basic_y (basic_x.get());
	basic_x->val = 20;
	cout << basic_y->val << std::endl;
	
	return 0;
	
	auto basic_a = make_shared<basic>(obj_1);

	auto basic_b = basic_a;
	if (basic_a == basic_b)
		cout << "equal";
	else
		cout << "not equal";
 
#if 0
	auto a = make_shared<int>(10);
	auto b = make_shared<int>(10);
	if (*a == *b)
		cout << "equal";
	else
		cout << "not equal";
#endif

	return 0;
}
