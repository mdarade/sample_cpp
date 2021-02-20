#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

using HycNetClock = std::chrono::high_resolution_clock;
using HycNetTimePoint = std::chrono::high_resolution_clock::time_point;

void f1() {
		std::chrono::duration<int, std::milli> timespan(20);


		HycNetTimePoint send_at_ = HycNetClock::now();
		std::this_thread::sleep_for(timespan);
		HycNetTimePoint recv_at_ = HycNetClock::now();

		auto dur_ns = std::chrono::duration_cast<chrono::nanoseconds>(recv_at_ - send_at_);
		std::cout << dur_ns.count() << endl;
}

int main() {
	f1();
	return 0;
}
