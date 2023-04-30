#include <iostream>
#include <utility>

using namespace std;

void f3(int &&a) {
	std::cout << "inside f3";
	std::cout << a << std::endl;
	a = 40;
	std::cout << a << std::endl;
	std::cout << "going out of f3" << std::endl;
}

void f2(int &&a) {
	std::cout << "inside f2";
	std::cout << a << std::endl;
	a = 30;
	std::cout << a << std::endl;
	f3(std::forward<int>(a));
	std::cout << a << std::endl;
	std::cout << "going out of f2" << std::endl;
}

void f1(int &a) {
	std::cout << "inside f1";
	std::cout << a << std::endl;
	a = 20;
	std::cout << a << std::endl;
	f2(std::move(a));
	std::cout << a << std::endl;
	std::cout << "going out of f1" << std::endl;
}	


int main() {
	int a=10;
	std::cout << "inside main" << std::endl;
	std::cout << a << std::endl;
	f1(a);
	std::cout << a << std::endl;
	std::cout << "going out of main" <<std::endl;
	return 0;
}
