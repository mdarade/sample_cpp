#include <iostream>
#include <set>

using namespace std;

struct Pair {
    int key;
    int value;
    bool operator<(const Pair& other) const {
        return value < other.value;
    }
};

int main() {
    set<Pair> store;
    store.insert({800,9000});
    store.insert({600, 6000});
    store.insert({700, 7000});
    for (auto [k,v]: store) {
        cout << k << ":" << v << std::endl;
    }
    return 0;
}