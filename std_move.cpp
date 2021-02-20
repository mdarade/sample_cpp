#include <iostream>
using namespace std;

void f1(const std::string& str) {
	cout << "inside";
}

void f2(const int* ptr) {
	cout << *ptr++ << endl;
	cout << *ptr++ << endl;
}

int main() {
	//std::string *str= new std::string("mahaveer");
	int *ptr = new int[10];
	ptr[0]=1;
	ptr[1]=2;
	//f1(std::move(str));
	f2(std::move(ptr));
	return 0;
}

