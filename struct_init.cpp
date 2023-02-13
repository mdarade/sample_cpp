#include <iostream>

using namespace std;

struct In {
	In(int a, int b) : a_(a), b_(b) {}
	int a_;
	int b_;
};

int main() {
	In in(10,20);
	cout << in.a_ << std::endl;
	return 0;
}
