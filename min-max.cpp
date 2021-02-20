#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> arr = {4,2,3};
	int i =0;
	int j = arr.size()-1;
	
	cout << std::min(arr[i], arr[j]) << std::endl;

	return 0;
}
