#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	string str = "geeksforgeeks";
	vector<char> store;
	for(auto& itr: str) {
		if (store.begin()
		store.push_back(itr);
	}
	for(auto& itr: store)
		cout << itr.first << ":" << itr.second <<  std::endl;

	return 0;
}
