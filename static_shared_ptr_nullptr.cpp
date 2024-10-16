#include <algorithm>
#include <iostream>
#include <memory>
#include <cassert>
#include <optional>

using namespace std;

struct SigManager {
    bool initialized_;
};

static shared_ptr<SigManager> instance(std::optional<shared_ptr<SigManager>> sptr = std::nullopt) {
    static shared_ptr<SigManager> s_sm;
    if (sptr.has_value()) {
        std::cout << "resetting s_sm" << std::endl;
        s_sm = move(sptr.value());
    }
    cout << "Hello, World!" << endl;
    // assert(s_sm != nullptr);
    return s_sm;
}

int main() {
    //std::cout << instance(nullptr)->initialized_ << std::endl;
    auto obj = instance();
    std::cout << obj->initialized_ << std::endl;
    return 0;
}
