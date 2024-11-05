#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<tuple<double, char, string>> data = {
        {3.14, 'A', "apple"},
        {2.71, 'B', "banana"},
        {1.618, 'C', "carrot"}
    };

    // Sort the vector by the 3rd element (string) in ascending order
    sort(data.begin(), data.end(), [](const tuple<double, char, string>& a, const tuple<double, char, string>& b) {
        return get<2>(a) < get<2>(b);
        // descending order
        // return get<2>(a) > get<2>(b);
    });

    // Print the sorted data
    for (const auto& tuple : data) {
        cout << get<2>(tuple) << " " << get<1>(tuple) << " " << get<0>(tuple) << endl;
    }

    return 0;
}