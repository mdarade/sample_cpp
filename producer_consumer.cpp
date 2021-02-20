#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <deque>

using namespace std;

std::deque<int> buffer;
std::condition_variable cv;
std::mutex mt;

const unsigned int k_max_buff_size = 20;
const unsigned int k_run_till_cnt = 100;


void producer() {
	unsigned int cnt = 0;
	while(cnt < k_run_till_cnt) {
	//while(true) {
			std::unique_lock<std::mutex> lock(mt);
			cv.wait_for(lock, 10ms, [](){return buffer.size() < k_max_buff_size;});
			buffer.push_back(cnt);
			cout << "produced:" << cnt << std::endl;
			cnt++;
			lock.unlock();
			cv.notify_one();
	}
}


void consumer() {
	unsigned int cnt = 0;
	while (cnt < k_run_till_cnt) {
	//while (true) {
			std::unique_lock<std::mutex> lock(mt);
			cv.wait_for(lock, 10ms, [](){return buffer.size() > 0;});
			cout << "consumed:" << buffer.front() << std::endl;
			buffer.pop_front();
			cnt++;
			lock.unlock();
			cv.notify_one();
	}
}


int main() {
	std::thread t1(producer);
	std::thread t2(consumer);

	cout << "join started" << std::endl;
	t1.join();
	cout << "joined t1" << std::endl;
	t2.join();
	cout << "joined t2" << std::endl;

	return 0;
}
