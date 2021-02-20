#include <iostream>
#include <mutex>  // For std::unique_lock
#include <shared_mutex>
#include <thread>

using namespace std;
 
class ThreadSafeCounter {
 public:
  ThreadSafeCounter() = default;
 
  //Notice *shared_lock* for Multiple threads/readers to acces same time.
  unsigned int get() const {
    std::shared_lock lock(mutex_);
	cout << "reader getting counter:" << value_ << std::endl;
    return value_;
  }
 
  //Notice *unique_lock* for exclusive access.
  //Only one thread/writer can increment/write the counter's value.
  void increment() {
    std::unique_lock lock(mutex_);
	cout << "writer updated counter:" << ++value_ << std::endl;
  }
 
  // Only one thread/writer can reset/write the counter's value.
  void reset() {
    std::unique_lock lock(mutex_);
    value_ = 0;
  }
 
 private:
  mutable std::shared_mutex mutex_; //Notice its *shared_mutex* 
  unsigned int value_ = 0;
};
 

int main() {
  ThreadSafeCounter counter;
 
  auto increment_and_print = [&counter]() {
    for (int i = 0; i < 3; i++) {
      counter.increment();
      std::cout << std::this_thread::get_id() << counter.get() << '\n';
 
      // Note: Writing to std::cout actually needs to be synchronized as well
      // by another std::mutex. This has been omitted to keep the example small.
    }
  };
 
  std::thread thread1(increment_and_print);
  std::thread thread2(increment_and_print);
  std::thread thread3(increment_and_print);
  std::thread thread4(increment_and_print);
  std::thread thread5(increment_and_print);
 
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();

  return 0;
}
