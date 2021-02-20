#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::string str ={0};
	int num = 4;
	str += std::to_string(num);
	str += std::to_string(9);
	str += std::to_string(5);
	
	cout << str << std::endl;
	
	
	return 0;
}
