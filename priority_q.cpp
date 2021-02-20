#include <iostream>
#include <queue>

using namespace std;
int main() {
	std::priority_queue<int, vector<int>, greater<int>> max_heap;
	
	max_heap.push(1);
	max_heap.push(2);
	max_heap.push(3);
	max_heap.push(4);
	max_heap.push(5);
	
	//TBD read next ele from FILE
	int num = 6;
	
	if (num > max_heap.top()) {
		max_heap.pop();
		max_heap.push(num);
	}
	
	while (max_heap.size()) { 
		auto ele = max_heap.top();
		max_heap.pop();
		cout << ele << std::endl;
	}

	return 0;
}
