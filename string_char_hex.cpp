#include <iostream>
#include <boost/algorithm/hex.hpp>
#include <string>
#include <iterator>

int main() {
    // Input hexadecimal string
    std::string hex_input = "48656c6c6f20576f726c64"; // "Hello World" in hex

    try {
        std::string output;

        // Unhex the input using Boost's unhex algorithm
        boost::algorithm::unhex(hex_input.begin(), hex_input.end(), std::back_inserter(output));

        // Output the decoded string
        std::cout << "Decoded string: " << output << std::endl;
    }
    catch (const boost::wrapexcept<boost::algorithm::non_hex_input>& e) {
        std::cerr << "Error: Non-hex input detected!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

