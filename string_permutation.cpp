#include <iostream>
#include <string>
using namespace std;

void permute(string input, int l, int r) {
	
	if  (l == r)
		cout << input << std::endl;
	//l, r
	//swap l with i
	for (int i=l; i<=r; i++) {
		std::swap(input[l], input[i]);
		permute(input, l+1, r);
		std::swap(input[l], input[i]);
	}
}

int main() {
	string input = "ABC";
	permute(input, 0, input.size()-1);
	return 0;
}
