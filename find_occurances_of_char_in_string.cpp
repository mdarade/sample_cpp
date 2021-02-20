#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	string str_("hey howdy hows life going on?");
	std::map<int, int> map_;
	for(auto &c : str_) {
		cout << c <<  ":" << int(c) << endl;
		map_[int(c)]++;
	} 	

	for (auto &ele : map_) {
			cout << ele.first << ":" << ele.second << endl;
	}

	return 0;
}
