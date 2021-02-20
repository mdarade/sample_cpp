#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
	char a;
	cout << ":" << sizeof(a) << ":" << endl;
	unsigned char* data = new unsigned char('a');
	std::string hey(reinterpret_cast<const char*>(data));
	cout << hey << endl;
	return 0;
}
