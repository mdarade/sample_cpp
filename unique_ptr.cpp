#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

class VarStore { 
	public:
		VarStore(int value) : var_(value) {}
		void SetVar(int value) { var_ = value; }	
		int GetVar() { return var_; } 
	private:
		int var_{0};
};


void thread_function_1(unique_ptr<VarStore>& obj_ptr, int sleep_time) {
//void thread_function_1(unique_ptr<VarStore*> obj_ptr, int sleep_time) {
	cout << "sssleeping for " << sleep_time << " seconds" << endl;
	sleep(sleep_time);
	obj_ptr.reset();	
	cout << "deleted obj ptr" <<  obj_ptr.get() << endl;
	//cout << "sptr usage cnt is:" << sptr.use_count() << endl;
	//sptr.reset();
}


void thread_function_2(unique_ptr<VarStore>& sptr, int sleep_time) {
	cout << "sleeping for " << sleep_time << " seconds" << endl;
	sleep(sleep_time);

	if (sptr)
		cout << "sptr is still there:" << sptr.get() << endl;
	else 
		cout << "uniq ptr is no more valid as it got deleted in another thread" << endl;
//		sptr.reset();

}

void set(unique_ptr<VarStore> obj) {
	auto ptr = std::move(obj);	
}

int main() {
	unique_ptr<VarStore> sptr = make_unique<VarStore>(1); 
	auto obj1 = sptr.get();

	set(std::move(sptr));	

	cout << "its:" << obj1->GetVar() << endl;
	thread t1(thread_function_1, std::ref(sptr), 1);
	thread t2(thread_function_2, std::ref(sptr), 2);
	t1.join();
	cout << "join on t1 complete" << endl;
	t2.join();
	return 0;
}
