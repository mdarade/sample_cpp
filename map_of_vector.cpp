#include <map>
#include <vector>
#include <iostream>

using namespace std;


// Use as multimap
// you can sort values for any single key
 
int main() {

	map<int, vector<int>> store;
	// store[1] = {}; // works
	store[2].push_back(23);
	store[2].push_back(21);
	store[2].push_back(22);
	store[1].push_back(12);
	store[1].push_back(11);


	for (auto [k,v]: store) {
		std::sort(v.begin(), v.end());
		for (auto ele : v) {
			cout << "key=" << k << " val=" << ele << std::endl;
		}
	}

	return 0;

}
