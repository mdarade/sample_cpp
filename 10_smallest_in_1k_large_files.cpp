#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define MAX_SIZE 10

class HeapStore {
	public:
		HeapStore(std::string filepath) {
			 filepath_ = filepath;
			 fd_.open(filepath_, std::ifstream::in);
		}
			 
		~HeapStore() {
			fd_.close();
		}
			 
		void UpdateHeap(int num); 
		int GetNumber();

	private:
		//std::priority_queue<int, vector<int>, greater<int>> store_;
		std::priority_queue<int> store_;
		std::ifstream fd_;
		string filepath_;
};


int HeapStore::GetNumber() {
	std::string line;
	std::getline(fd_, line);
	return std::stoi(line);
}

void HeapStore::UpdateHeap(int num) {
	if (store_.size() < MAX_SIZE) {
		store_.push(num);
	} else {
		if (num < store_.top()) {
			//heapify case
			cout << "poping:" << store_.top() << "for:" << num << std::endl;
			store_.pop();
			store_.push(num);
		}
		else {
				//skipping num larger than 1st 10
				cout << "skipping:" << num << std::endl;
		}
	}
}
		
int main() {
	std::string filepath;
	cout << "enter file path:";
	//provide input path as /home/md/numbers.txt
	cin >> filepath;
	HeapStore obj(filepath);
	int cnt = 0;
	while(cnt < 20) {
		auto num = obj.GetNumber();
		obj.UpdateHeap(num);
		cnt++;
	}
	return 0;
}
