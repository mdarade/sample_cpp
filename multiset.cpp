#include <iostream>
#include<set>

using namespace std;

int main() {

	//std::multiset<int> a = {1,2,2,3,3,3};
	std::multiset<int> a;
	a.insert(4);
	a.insert(2);
	a.insert(1);
	a.insert(3);
	for (auto & i : a) {
		cout << i << std::endl;
	}
	//cout << "4 appears " << a.count(4) << " times in given set" << std::endl;
	//cout << "3 appears " << a.count(2) << " times in given set" << std::endl;

	return 0;
}

