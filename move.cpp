#include <iostream>
#include <map>

using namespace std; 


struct Opaque {
	int a{0};
	int b{0};
};

using DataMap = map<int, Opaque>;


class A {
public:
	void UpdateMap(Opaque& obj) {
			map1_.insert(make_pair(1,std::move(obj)));
	}
	void PrintMap() {
		for (auto& itr: map1_) {
			cout << itr.first << ":::" << itr.second.a <<endl;
		}
	}
	DataMap GetMeCopy() { return map1_; } 

private:
	DataMap map1_;
};


void PrintMap(DataMap map1) {
	for (auto& itr: map1) {
		cout << itr.first << ":::" << itr.second.a <<endl;
	}
}



int main() {
	Opaque obj;
	obj.a = 10;
	obj.b = 20;
	A a;


	a.UpdateMap(obj);
	a.PrintMap();

	auto map_copy_ = a.GetMeCopy();
	PrintMap(map_copy_);

	return 0;
}
	
