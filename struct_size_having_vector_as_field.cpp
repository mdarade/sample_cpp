#include <iostream>
#include <vector>

using namespace std;


int main() {

	typedef struct a {
		vector<int> vec = {10,20,1,2,2,2,22,2,2,1,2,2,22,1,22,2,2,1,2,2,2,22,1,2,2,2,2,2,2,22,2,1,2,2,22,2,2,2,2,2,2,2,2,2,2,22};
		uint64_t f2;
	} a_t;

	a_t obj;
	std::cout << sizeof(obj) << std::endl;

	return 0;
}
