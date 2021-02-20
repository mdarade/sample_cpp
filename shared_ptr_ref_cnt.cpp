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


map<int, shared_ptr<VarStore>> map_;
using Map = map<int, shared_ptr<VarStore>>;

void StoreValIntoMap(int index, shared_ptr<VarStore> ptr) {
	map_[index] = ptr;
}

void StoreRefIntoMap(int index, shared_ptr<VarStore>& ptr) {
	map_[index] = ptr;
}

shared_ptr<VarStore> GetValByIndex(int key) {
	return map_[key];
}

shared_ptr<VarStore>& GetValByRef(int key) {
	return map_[key];
}

void FnByVal(shared_ptr<VarStore> ptr) {
	cout << __func__ << ptr.use_count() << endl;
}

void FnByRef(shared_ptr<VarStore>& ptr) {
	ptr->SetVar(10);
	cout << __func__ << ptr.use_count() << endl;
}

int main() {
	
	shared_ptr<VarStore> sptr = make_shared<VarStore>(1);

	StoreValIntoMap(1, std::move(sptr));
	//StoreRefIntoMap(1, sptr);

	cout << sptr.use_count() << endl;

	auto &objx = GetValByRef(1);	
	cout << objx.use_count() << endl;

	FnByVal(objx);
	cout << objx.use_count() << endl;
	FnByRef(objx);
	cout << __func__ << objx->GetVar() << endl;	
	cout << objx.use_count() << endl;


	return 0;

	auto obj = GetValByIndex(1);	
	cout << obj.use_count() << endl;

	return 0;
}

