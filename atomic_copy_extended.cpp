#include <iostream>
#include <atomic>
#include <cstring>

using namespace std;


class vmdkcachestats {
public:
	vmdkcachestats() { }
	vmdkcachestats(uint64_t arg1) : cnt_(arg1) {}

	vmdkcachestats& operator=(volatile vmdkcachestats& other) {
			atomic_store(&cnt_, atomic_load(&other.cnt_));
			uint64_t tmp = atomic_load(&other.cnt_);
			cout << "moving into non-atomic from atomic " << tmp << '\n';
	
	} 
	std::atomic<uint64_t> cnt_;
}; 


int main() {

	vmdkcachestats obj2, obj1(10);
	obj2 = obj1;	
	cout << "final val is " << obj2.cnt_ << '\n';
	return 0;
}
