#include <iostream>
#include <limits>

using namespace std;

int main() {
	int i, j, k;

	i = (j == 4) + (k =7);

	cout << i << std::endl;

	cout << "int max is:" << std::numeric_limits<int>::max();
	return 0;
}
	
