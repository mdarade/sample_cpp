#include <iostream>
#include <set>
 
// print out a container
template<class Os, class K>
Os& operator<<(Os& os, const std::multiset<K>& v)
{
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}
 
int main()
{
    std::multiset<char>
        p{'C', 'B', 'B', 'A'}, 
        q{'E', 'D', 'E', 'C'};
 
    std::cout << "p: " << p << "q: " << q;
 
    std::cout << "merge is available only c++17 onwards" << std::endl;
    std::cout << "compile with --std=c++17" << std::endl;
    
    p.merge(q);
 
    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;
}