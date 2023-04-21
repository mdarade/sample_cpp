#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
	std::array<uint8_t, 32> hash{0};
	std::string hash_str = "0xa";
	std::copy(hash_str.begin(), hash_str.end(), hash.begin());

	for (auto c: hash) {
		std::cout << c << std::endl;
	}

	std::cout << "size is " << sizeof(hash) << std::endl;
	return 0;
}
