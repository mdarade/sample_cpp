#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::vector<int> vec1 = {1,2,3};
	std::vector<int> vec2 = {4,5,6};
	std::vector<std::pair<int,int>> target;
	target.reserve(vec1.size());
	
	std::transform(vec1.cbegin(), vec1.cend(), vec2.begin(), std::back_inserter(target), 
			[](int a, int b) { return std::make_pair(a,b); });


	for (auto [a, b]: target) {
		std::cout << a << "," << b << std::endl;
	}

	return 0;
}
	
