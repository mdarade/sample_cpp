#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void find_and_replace_occurances(std::string& str, std::string spattern, std::string rpattern) {
	int pos = str.find(spattern);
	while (pos != std::string::npos) {
			str.replace(pos, spattern.size(), rpattern);
			pos = str.find(spattern, pos+spattern.size());
	}
}


int main()
{
    std::string str("The quick brown fox jumps quick over the quick lazy dog.");
	std::string spattern = "quick";
	std::string rpattern = "slower";

	find_and_replace_occurances(str, spattern, rpattern);

	//print result
	cout << str << std::endl;

	return 0; 
}
