#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <experimental/future>

using namespace std;

int main() {
	std::vector<std::future<int>> futures;
	std::vector<int> result(10);
	
	for (int i=0; i<10; i++) {
		std::future<int> f = std::async(std::launch::async, [](int i, std::vector<int>& result) { result[i]=i; std::cout << "thread=" << i << std::endl; });
		futures.push_back(f);
	}

	std::experimental::when_all(futures);
	std::cout << "futures size" << futures.size() << std::endl;
	return 0;
}

