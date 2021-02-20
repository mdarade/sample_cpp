#include <iostream>
#include <array>

using namespace std;

int main() {
	int ar[] = {1,2,3};
	int arr_copy [] = sizeof(ar); //size can't be derived at compile time
	for (auto& i: arr_copy)
		cout << i;

	return 0;


	array<char, 3> arr;
	arr[1] = 'c';
	for (char c : arr)
		cout << c;
	return 0;
}

