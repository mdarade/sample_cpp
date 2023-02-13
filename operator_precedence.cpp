#include <iostream>
#include <limits>

using namespace std;

int main () {

	static constexpr size_t kNIDBitsPerLevel = 8;
	static constexpr size_t kRVTMaxLevels = (0x1 << kNIDBitsPerLevel);
	static constexpr uint64_t kRvbIndexMask = (kRVTMaxLevels - 1) << ((sizeof(uint64_t) * 8) - kNIDBitsPerLevel);
	static constexpr uint64_t kRvbIdMask = std::numeric_limits<uint64_t>::max() & (~kRvbIndexMask);

	cout << std::hex << kRvbIndexMask << std::endl;
	cout << std::hex << kRvbIdMask << std::endl;

    	return 0;

	int a = (0x1 << 8) - 1;
	cout << a;
	return 0;
}
