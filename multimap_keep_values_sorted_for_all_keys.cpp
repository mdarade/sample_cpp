#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    // Map with a set to keep values sorted within each key
    std::map<std::string, std::set<int>> sortedMultiMap;

    // Inserting elements into the map
    sortedMultiMap["Category1"].insert(50);
    sortedMultiMap["Category1"].insert(10);
    sortedMultiMap["Category1"].insert(30);
    sortedMultiMap["Category2"].insert(40);
    sortedMultiMap["Category2"].insert(10);

    // Printing the elements to see if values are sorted within each key
    for (const auto& [key, values] : sortedMultiMap) {
        for (const auto& value : values) {
            std::cout << key << ": " << value << std::endl;
        }
    }

    return 0;
}