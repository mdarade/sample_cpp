#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Item {
    string key;
    string val;
};

// Custom comparator to sort by value in descending order
struct compareByValueDesc {
    bool operator()(const Item& a, const Item& b) const {
        return a.val > b.val;
    }
};

// Custom comparator to sort by key in descending order
struct compareByKeyDesc {
    bool operator()(const Item& a, const Item& b) const {
        return a.key > b.key;
    }
};

int main() {
    // Map with a set to keep values sorted within each key
    map<int, set<Item, compareByValueDesc>> myMap;
    // map<int, set<Item, compareByKeyDesc>> myMap;

    myMap[2].insert({"key20", "valb"});
    myMap[1].insert({"key20", "val20"});
    myMap[2].insert({"key20", "vala"});

    // Iterate and print the elements in descending order by value
    for (const auto& [mkey, values] : myMap) {
        for (const auto& [key, val] : values) {
            cout << mkey << " " << key << " " << val << endl;
        }
    }

    return 0;
}