#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    std::multimap<string, char, std::greater<>> store{{"dea", 'a'}, {"dex", 'b'}};
    for (auto ele: store) {
        std::cout << ele.first << "," << ele.second << std::endl;
    }
    return 0;
}
