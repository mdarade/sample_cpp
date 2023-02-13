#include <future>
#include <utility>
#include <array>
#include <iostream>
#include <optional>
#include <vector>

using BlockDigest = std::array<std::uint8_t, 32>;
// using BlockDigest = int;

std::optional<BlockDigest> getDigest() {
  // BlockDigest opt = 10;
  BlockDigest opt = {'a', 'b'};
  return std::make_optional<BlockDigest>(opt);
}

std::future<std::optional<BlockDigest>> getFutureForDigest() {
  // BlockDigest opt = 10;
  BlockDigest opt = {'a', 'b'};
  return std::async([opt]() { return std::make_optional<BlockDigest>(opt); });
}

int main() {
  std::vector<std::future<std::optional<BlockDigest>>> futures;

  for (size_t i = 0; i < 2; i++) {
    auto ft = getFutureForDigest();
    std::cout << std::boolalpha << ft.valid() << std::endl;
    futures.push_back(std::move(ft));
  }

  std::cout << "futures size is " << futures.size() << std::endl;
  // std::future<std::optional<BlockDigest>> f = futures.pop_back(); // does not work

  auto f = std::async([]() { return getDigest(); });
  if (f.valid()) {
    auto oopt = f.get();
    if (oopt.has_value()) {
      auto digest = oopt.value();
      for (auto d : digest) {
        std::cout << d;
      }
      std::cout << "\n";
    }
  }
  return 0;
}