#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {

	std::ostringstream oss;
	int i=0;
	while (i++ < 3) {
		oss << std::to_string(i) << " ";
	}
	cout << oss.str();

	return 0;
}

