#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void find_all_occurances(std::string str, std::string pattern, vector<int>& res) {
	int pos = str.find(pattern);
	if (pos != std::string::npos)
			res.push_back(pos);

	while (1) {
			pos = str.find(pattern, pos+pattern.size());
			if (pos == std::string::npos)
				break;
			res.push_back(pos);
	}
}


int main()
{
	vector<int> posn;
    std::string str("The quick brown fox jumps quick over the quick lazy dog.");
	std::string pattern = "quick";
	find_all_occurances(str, pattern, posn);

	//print result
	for (auto i: posn)
		cout << i << std::endl;

	return 0; 
}
