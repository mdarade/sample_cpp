#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<vector<int>> bucket_;
	bucket_.reserve(16);
	bucket_.resize(16, std::vector<int>(128));	

	for (auto i : bucket_) {
		i.reserve(128);
		std::fill(i.begin(), i.end(), 0);
	}	


	int latency=0;
    int req_cnt=5;
	bucket_[latency][req_cnt]+=1;	



	cout << "ele at [0][5] index is " << bucket_[0][5] << endl;

	for (auto i : bucket_) {
		for (auto j : i) {
			cout << j << ",";
		}
		cout << endl;
	}

	return 0;
}

