#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	vector<string> names;
	vector<map<string, string>> tags;

	names.push_back("metric1");
	using TagMap = map<string, string>;
       	TagMap tags_map;

	tags.push_back({});

	for (size_t index = 0; index < names.size(); index++) {
		cout << "name:" << names[index] << std::endl;
		cout << "tags size:" << tags[index].size() << std::endl;
	}

	return 0;
}
