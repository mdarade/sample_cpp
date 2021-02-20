#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	const char* key = "n_msg";
	std::unordered_multimap<string, uint64_t> map_;
	map_.emplace(std::string(key), 100);

	for (auto& itr: map_)
		cout << itr.first << "," << itr.second << std::endl;

	return 0;
}
