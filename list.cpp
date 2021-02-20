#include <iostream>
#include <list>

using namespace std;

int main() {

	std::list<int> numbers = {1, 2, 3, 4, 5};

	for (auto itr: numbers) {
		cout << itr << std::endl;
	}

	return 0;
}
