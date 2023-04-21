#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> n;	
	// int x = 10;
	cout << "n size is " << n.size() << std::endl;
	for (int i: n) {
		cout << "inside loop" << std::endl;
		cout << i << std::endl;
	}
	return 0;
}
