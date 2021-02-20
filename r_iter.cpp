#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
	std::map<uint64_t, bool> predictions;
	predictions.insert(std::make_pair(10,true));
	predictions.insert(std::make_pair(20,true));
	predictions.insert(std::make_pair(30,true));
	predictions.insert(std::make_pair(40,true));
	predictions.insert(std::make_pair(50,true));
	uint32_t extra = 5;
	//using RevIter = std::reverse_iterator<std::map<uint64_t, bool>::iterator>;
	while (extra--) {
		auto riter = predictions.rbegin();
		cout << "rit is " << riter->first << endl;
		predictions.erase(riter.base());
	}
	cout << "predictions size is " << predictions.size() << endl;

	return 0;
}
