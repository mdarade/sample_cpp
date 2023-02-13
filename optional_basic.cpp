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
  // BlockDigest opt = {'a', 'b'};
  // return std::make_optional<BlockDigest>(opt);

  // std::optional<BlockDigest> dg;
  // return dg;

  return std::optional<BlockDigest>{};

  // return std::make_optional<BlockDigest>(std::nullopt);
  // return std::nullopt;
}

int main() {
  auto oopt = getDigest();

  if (!oopt.has_value()) {
    std::cout << "optional does not contain any valid val" << std::endl;
    return -1;
  }

  auto digest = oopt.value();
  for (auto d : digest) {
    std::cout << d;
  }

  std::cout << "\n";

  return 0;
}
