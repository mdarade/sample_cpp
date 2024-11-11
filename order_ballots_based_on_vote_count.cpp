//List<String> getResults(List<Ballot> ballots)
//[[A,B,C]]

// results should be in reverse order - winner comes first in the list
// order has importance - A - 3 votes , B - 2 votes 
// candidates can be many
// ballot will have only 3 votes representing 3 candidates 

//List<String> getResults(list<Ballot> ballots)

// Example - 
// vector<string> getResults(vector<vector<string>> ballots)
// candiates - A B C D E F G H 
// list of ballots - [[A,B,C], [C,D,E], [G,A,B]]
// A:5, C-4, G-3, B-3, D-2, E-1
// output - [A,C,G,B,D,E]
//

// opti sol - 
// map  - candidate - to - total votes 
// ordering problem req - O(1)
// candidate  - 3 2 1 

// ballot1 - A B C
// ballot2 - C D E
// ballot3 - G A B
// 
//  A - 3,8 => 
//  B - 2,9 =>   
//  unordered_map<candidate, pair<total_vote_count, order>> store;
//  iterate over store
//  1. compare based on vote count 
//  in cae vote count same - then compare based on order


// solution  ver 1 - 
// map  - candidate - to - total votes 
// A - 5
// B - 3
// C - 4
// D - 2
// E - 1
// G - 3

// [ordering] based on total votes  - map<votes, list<candidates> 
// 3 -  G
// 2 - B, D
// 4 - C
// 1 - E
// 5 - A
// 
// - ignore - multiset<pair<int, string, std::greater<>>
// collision - list

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> getResults(vector<vector<string>>& ballots) {
    vector<string> result;
    int order = 0;
    unordered_map<string, pair<int, int>> store;
    for (auto ballot: ballots) {
        auto vote = 3;
        for (auto candidate: ballot) {
            auto itr = store.find(candidate);
            if (itr != store.end()) {
                auto vote_count = itr->second.first;
                store[candidate] = {vote_count+vote--, order++};
            } else {
                store.insert({candidate, {vote--, order++}});
            }
        }
    }

    // unordered_map hashes keys to support lookup in O(1) so comparator can't be used on keys
    // so, convert map to vector and sort it
    vector<pair<string, pair<int, int>>> vec(store.begin(), store.end());

    // sort vec based on vote count
    std::sort(vec.begin(), vec.end(), [&](auto a, auto b) {
         if (a.second.first == b.second.first) {
            return a.second.second > b.second.second;
        }
        return a.second.first > b.second.first;
    });

    // populate result - vote-count, order
    for (auto ele: vec) {
        std::cout << ele.first << " - " << ele.second.first << " - " << ele.second.second << std::endl;
        result.push_back(ele.first);
    }

    return result;
}


int main() {
    // TODO - input 
    vector<vector<string>> ballots = {{"A","B","C"}, {"C","D","E"}, {"G","A","B"}};
    auto result = getResults(ballots);
    for (auto res: result) {
        std::cout << res << std::endl;
    }
    return 0;
}