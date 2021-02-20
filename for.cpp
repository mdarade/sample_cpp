#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> n(8);	

	for (int i: n)
		cout << i << std::endl;

	return 0;
}
