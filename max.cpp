#include <iostream>
using namespace std;

void f1(std::string str) {
	cout << str << std::endl;
}

int main() {
	int j=1;
	//f1("state-"+ std::to_string(j));
	std::string full("full");
	std::string incr("incremental");
	f1((j?incr:full) + std::string(" state"));
	//cout << std::max(true, false);
	//cout << std::max(false, true);
	bool running = std::max(true, false);
	if  (running) 
		cout << "hello" << std::endl;
	else 
		cout << "world";
	return 0;
}
