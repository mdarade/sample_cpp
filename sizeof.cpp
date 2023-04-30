#include <iostream>
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	using a32bytes = std::array<uint8_t, 32>;
	cout << sizeof(a32bytes);
	return 0;

	uint64_t x;
	cout << ":" << sizeof(x) << ":" << endl;
	return 0;

	char a;
	cout << ":" << sizeof(a) << ":" << endl;
	unsigned char* data = new unsigned char('a');
	std::string hey(reinterpret_cast<const char*>(data));
	cout << hey << endl;
	return 0;
}
