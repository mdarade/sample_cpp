#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

std::mutex mt;
std::condition_variable cv;
int cnt;

bool should_cont() {
	return cnt < 10;
}

void consumer() {
	while (should_cont()) {
			unique_lock<mutex> lk(mt);
			cv.wait(lk, [](){return cnt%2==1;});
			cout << __func__ << std::endl;
			cnt++;
			cv.notify_all();
	}
}

int main() {
	std::thread t1(consumer);

	while (should_cont()) {
			unique_lock<mutex> lk(mt);
			cv.wait(lk, [](){return cnt%2==0;});
			cout << __func__ << std::endl;
			cnt++;
			cv.notify_all();
	}
	t1.join();
	return 0;
}


