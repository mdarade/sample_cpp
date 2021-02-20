#include <iostream>
#include <vector>

using namespace std;

using pair_t = std::pair<int, int>;

int main() {
	std::vector<pair_t> st = {{1,2}, {3,4}};
	for (auto& i: st) {
		cout << i.first << std::endl;
	}
	return 0;
}
