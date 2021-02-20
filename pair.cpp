#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
using node_t = std::pair<int, int>;

void print_list(std::list<node_t>& list_) {
	for (auto it : list_)
		cout << it.first << ":" << it.second << std::endl;
}


int main() {

	std::unordered_map<int, std::list<node_t>::iterator> umap_;
	std::list<node_t> list_;

	std::pair<int, int> pr = {10, 100};
	list_.push_back(pr);

	umap_[10] = list_.begin();

	pr.first = 20;
	pr.second = 200;
	list_.push_front(pr);
	umap_[20] = list_.begin();

	print_list(list_);

	int key = 20;

	auto it = umap_[key];
	auto& node = *it;
	node.first = 30;
	node.second = 300;
	
	cout << "============" << std::endl;
	print_list(list_);

	//dont use reference 
	//list_.erase(node);
	print_list(list_);

	return 0;
}
