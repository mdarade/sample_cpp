#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <deque>
#include <atomic>
#include <unistd.h>

using namespace std;


std::mutex mt;
std::deque<int> q;
#define MAX_SIZE 10
std::condition_variable cv;

#define MAX_RUNS 40
std::mutex run_mt;

int cnt;

bool should_continue(int runs) {
	//std::unique_lock<std::mutex> lk(run_mt);
    return runs < MAX_RUNS;
}

// Producer Consumer problem
void producer() {
	unsigned int runs = 0;
    while(should_continue(++runs))
    {
            unique_lock<std::mutex> lock(mt);
            cv.wait_for(lock, 10ms, [](){return q.size() < MAX_SIZE;});

        q.push_back(++cnt);
		//std::unique_lock<std::mutex> lk(run_mt);
        cout << "produced " << cnt << std::endl;
        cv.notify_all();
    }
}

void consumer() {
	int runs = 0;
    while(should_continue(++runs)) {
        unique_lock<std::mutex> lock(mt);
        cv.wait_for(lock, 10ms, [](){ return q.size() > 0;});
        auto data = q.front();
        q.pop_front();
		//std::unique_lock<std::mutex> lk(run_mt);
        cout << "consumed " <<  data << std::endl;
        cv.notify_all();
    }
}


int main() {
  std::thread t1(producer);
  std::thread t2(consumer);
  std::cout << "inside main" << std::endl;
  t1.join();
  t2.join();
  
  return 0;
}

