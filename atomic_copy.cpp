#include <iostream>
#include <atomic>
#include <cstring>

using namespace std;

class vmdkcachestats {
public:
	vmdkcachestats() { }
	//vmdkcachestats(uint64_t arg1) : cnt_(arg1) {}

#if 0
	vmdkcachestats& operator=(volatile vmdkcachestats& other) {
			atomic_store(&cnt_, atomic_load(&other.cnt_));
			uint64_t tmp = atomic_load(&other.cnt_);
			cout << "moving into non-atomic from atomic " << tmp << '\n';
	
	} 
#endif 

	struct {
			std::atomic<uint64_t> cnt_;
	} stats_;
	
}; 


int main() {

	vmdkcachestats* st = new vmdkcachestats();
	auto & stats_ref = st->stats_;
	st->stats_.cnt_ = 10;	

	cout << stats_ref.cnt_ << endl;

	//vmdkcachestats obj2, obj1(10);
	//obj2 = obj1;	
	//cout << "final val is " << obj2.cnt_ << '\n';
	return 0;
}
