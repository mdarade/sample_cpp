#include <map>
#include <iostream> 
using namespace std;

int main() {
	std::multimap<int, int> store;
	store.emplace(1, 10);
	store.emplace(2, 20);
	
	for (auto& itr: store)
			cout << itr.first << "=" << itr.second << std::endl;
	return 0;
}
