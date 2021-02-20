#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class VarStore { 
	public:
		VarStore(int value) : var_(value) {}
		void SetVar(int value) { var_ = value; }	
		int GetVar() { return var_; } 
	private:
		int var_{0};
};


//void thread_function_1(VarStore* obj_ptr, int sleep_time) {
void thread_function_1(shared_ptr<VarStore> ptr, int sleep_time) {
	stringstream msg;
	msg << "sssleeping for " << sleep_time << " seconds" << endl;
	cout << msg.str();
	sleep(sleep_time);
	//delete ptr.get();	
	//cout << "sptr usage cnt is:" << sptr.use_count() << endl;
	ptr.reset();
	cout << "deleted shared ptr" << endl;
}


void thread_function_2(const shared_ptr<VarStore>& ptr, int sleep_time) {
	stringstream msg;
	msg << "sptr usage cnt is:" << ptr.use_count() << endl;
	cout << msg.str();
	msg << "sleeping for " << sleep_time << " seconds" << endl;
	cout << msg.str();
	sleep(sleep_time);
	cout << "sptr usage cnt is:" << ptr.use_count() << endl;
	if (ptr.use_count()) 
		cout << "shouldnt be here" << endl;
	else
		cout << "nice" << endl;

#if 0
	weak_ptr<VarStore> wptr = sptr;
	if (auto sp = wptr.lock())
		cout << "sptr usage cnt is:" << sp.use_count() << endl;
	else 
		cout << "do nothing" << endl;
//		sptr.reset();
#endif

}

int main() {
	//VarStore* obj  = new VarStore(1);
	//shared_ptr<VarStore> sptr = obj;

	shared_ptr<VarStore> sptr = make_shared<VarStore>(1);

	auto obj1 = sptr.get();
	cout << "its:" << obj1->GetVar() << endl;

	thread t2(thread_function_2, sptr, 2);
	thread t1(thread_function_1, std::move(sptr), 1);

	t1.join();
	t2.join();
	return 0;
}
