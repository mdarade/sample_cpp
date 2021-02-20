#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

std::mutex mt;
std::condition_variable cv;

int counter;

bool should_continue() {
	return counter<10;
}

void helper () {
	while(should_continue()) {
		std::unique_lock<std::mutex> lk(mt);
		cv.wait(lk, []{ return ((counter%2)==1); });
		cout << __func__ << " has count: " << counter++ << std::endl;
		cv.notify_all();
	}
}

int main() {
	std::thread worker(helper);
	while (should_continue()) {
		{
			std::lock_guard<std::mutex> lock(mt);
			cout << __func__ << " has count: " << counter++ << std::endl;
		}
		cv.notify_all();

		std::unique_lock<std::mutex> lock(mt);
		cv.wait(lock, []{return counter%2==0; });
	}
	worker.join();
	return 0;
}
