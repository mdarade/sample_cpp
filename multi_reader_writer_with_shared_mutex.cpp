#include <mutex>
#include <shared_mutex>
#include <thread>
#include <iostream>

using namespace std;

class ThreadSafeCounter {
	public:
		ThreadSafeCounter() = default;
		void Increment() {
			std::unique_lock lock(mutex_);
			counter_++;
		}
		int Get() {
			std::shared_lock lock(mutex_);
			return counter_;
		}
	private:
		std::shared_mutex mutex_;
		unsigned int counter_ {0};
};


int main() {
	ThreadSafeCounter obj;
	auto incr_and_print = [&obj] () {
		for (int i=0; i<3; i++) {
			obj.Increment();
			obj.Get();
			cout << "counter:" << std::this_thread::get_id() << '\n';
		}
	};
	std::thread t1(incr_and_print);
	std::thread t2(incr_and_print);
	t1.join(); t2.join();
	return 0;
}

