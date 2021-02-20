#include <iostream>
#include <map>
#include <atomic>

using namespace std;

typedef struct {
	std::atomic<int> a;
}a_t;

std::map<std::string, a_t> map_;

void f1(std::string vmid) {
	//a_t obj;
	map_.emplace(std::piecewise_construct, std::make_tuple(vmid), std::make_tuple());
}

int main() {
	std::string vmid = "vm-1";
	f1(vmid);	
	int cnt=0;

	auto it = map_.find(vmid);
	if (it == map_.end()) {
		std::cout << vmid << " not found" << std::endl;
	}
	std::cout << it->second.a; 


	for (auto& itr : map_) {
		itr.second.a = ++cnt;
		std::cout << itr.first << ":::" << itr.second.a; 
	}
	return 0;
}

