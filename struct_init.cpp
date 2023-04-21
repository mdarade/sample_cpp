#include <iostream>

using namespace std;

struct In {
	In(int64_t a, int64_t b, char c) : a_(a), b_(b), c_(c) {}
	void display_a() {
		std::cout << a_ << std::endl;
	}
	void display_b() {
		std::cout << b_ << std::endl;
	}
	int64_t a_;
	int64_t b_;
	char c_;
};

int main() {
	In in(10,20,'a');
	// cout << in.a_ << std::endl;
	cout << sizeof(in) << std::endl;
	return 0;
}
