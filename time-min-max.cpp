#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

void f1() {
std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
auto duration = now.time_since_epoch();

uto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

std::cout << hours.count() << ":"
          << nanoseconds.count() << std::endl;
}

int main() {
	f1();
	return 0;
}
