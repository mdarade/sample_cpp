#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <map>

std::map<uint64_t, uint64_t> m;

void init_map() {
    for (uint64_t i=0; i<500000; i++) {
        m[i] = i*10;
    }
}

void f1()
{
    for (uint64_t i = 0; i < 500000; ++i) {
        std::cout << "erase i=" << i << " \n";
        if (m.count(i)) {
            m.erase(i);
        }
    }
}
 
void f2()
{
    for (uint64_t i = 0; i < 500000; ++i) {
        std::cout << "new i=" << i << " \n";
        m[i] = i * 15;
    }
}

 
 
int main()
{
    init_map();
    std::thread t2(f1); // pass by value
    std::thread t3(f2); // pass by reference
    
    t2.join();
    t3.join();
    
    std::cout << "Final size of m is " << m.size() << '\n';
   
}
