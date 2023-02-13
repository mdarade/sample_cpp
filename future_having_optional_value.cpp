#include <future>
#include <utility>
#include <array>
#include <iostream>
#include <optional>

int main() {
    using BlockDigest = std::array<std::uint8_t, 32>; 
    std::promise<std::optional<BlockDigest>> p;
    std::future<std::optional<BlockDigest>> f = p.get_future();
 

    //BlockDigest dg{"0xa"};
    //std::memcpy(dg.data(), "0xa", 32);
    p.set_value(std::nullopt);
    std::cout << std::boolalpha << f.valid() << '\n';
    if (f.valid()) {
        if (f.get().has_value()) {
            auto digest = f.get().value();
            for (auto d: digest) {
             std::cout << d;
            }
        }
    } else {
        std::cout << "doomed";
    }
    return 0;
}
