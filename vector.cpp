#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {


	vector<map<int,int>> xxx;
	xxx.emplace_back({});
	xxx.emplace_back({});
	std::cout << xxx.size() << std::endl;
	// std::cout << xxx[1];
	return 0;

	vector<int> d;
	//d.emplace_back(1,2);
	//cout << *std::min_element(d.begin(), d.end());
	//return 0;

	d.push_back(3);
	d.push_back(1);
	d.push_back(2);
	d.push_back(4);
	cout << *std::min_element(d.begin(), d.end());
	return 0;

	cout << "ele at front is " << d.front() << endl;
	cout << "ele at back is " << d.back() << endl;
	cout << "ele at [1] index is " << d[1] << endl;
	d.erase(d.begin()+1);
	cout << "ele at [1] index is " << d[1] << endl;
	return 0;

	vector<vector<long>> data = {{1,2,3},{4,5,6},{7,8,9}};
	for (auto i : data) {
		for (auto j : i) {
			cout << j << endl;
		}
	}

	return 0;
}

