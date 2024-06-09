#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string str="mahaveer";
	size_t pos = str.find("havee");
	if (pos != string::npos) {
		std::cout << "found at " << pos << std::endl;
	} else {
		std::cout << "not found" << std::endl;
	}
	return 0;
}
