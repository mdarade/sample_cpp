#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    std::multimap<int, char> dict
    {
        {1, 'A'},
        {2, 'B'},
        {2, 'D'},
        {2, 'C'},
        {4, 'E'},
        {3, 'F'}
    };
 
    auto range = dict.equal_range(2);
 
    for (auto i = range.first; i != range.second; ++i)
        std::cout << i->first << ": " << i->second << '\n';
    
    std::multiset<char, std::greater<>> store;
    for (auto i = range.first; i != range.second; i++)
        store.insert(i->second);
    
    // print all values in descending order
    for (auto ele: store)
        std::cout << ele << std::endl;
    
        
}
