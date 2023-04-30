#include <iostream>
#include <array>

using namespace std;

int main() {
	array <int, 3> xa = {0,0,0};
	array <int, 3> xb = {0,0,0};

	std::copy(xa.begin(), xa.end(), xb.begin());
	return 0;


	/*
	int ar[] = {1,2,3};
	int arr_copy [] = sizeof(ar); //size can't be derived at compile time
	for (auto& i: arr_copy)
		cout << i;
	return 0;
	*/


	array<char, 3> arr;
	arr[1] = 'c';
	for (char c : arr)
		cout << c;
	return 0;
}

