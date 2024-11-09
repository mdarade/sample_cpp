#include <iostream>
#include <set>

using namespace std;

struct compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    // this default compareator also has same effect
    //multiset<pair<int, string>, std::greater<>> store;
    multiset<pair<int, string>, compare> store;
    store.insert({100, "one"});
    store.insert({200, "two"});
    store.insert({300, "y"});
    store.insert({300, "x"});
    store.insert({300, "w"});
    store.insert({300, "z"});
    for (auto& i : store) {
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;
}