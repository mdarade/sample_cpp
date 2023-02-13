#include <iostream>
using namespace std;

static constexpr size_t EID_BITS_PER_LEVEL = 8;
static constexpr size_t RVT_MAX_LEVELS  = 2 << EID_BITS_PER_LEVEL;
static constexpr uint64_t kMaskMSByte = 0x00FFFFFFFFFFFFFF;

struct ENID {
  // ENID(uint64_t num) : level(num >> 56), rvb_index(num & kMaskMSByte) {}
  // ENID(uint8_t l, uint64_t idx) : level(__builtin_bswap64(static_cast<uint64_t>(l))), rvb_index(idx & kMaskMSByte) {}
  ENID(uint8_t l, uint64_t idx) : level(l), rvb_index(idx & kMaskMSByte) {}
  uint64_t level : EID_BITS_PER_LEVEL;
  uint64_t rvb_index : (64 - EID_BITS_PER_LEVEL);
  uint64_t get() { 
	  return ((static_cast<uint64_t>(level)<<56) | rvb_index);
  }
};

int main() {
	//ENID num(0x1010000000000000);
	//ENID num(0x10, 0x1110000000000000);
//	for (int i=1; i<=5; i=i+4) {
		ENID num(3, 1);
		cout << num.level << std::endl;
		cout << num.rvb_index << std::endl;
		cout << num.get()<< std::endl;
//	}
		
	return 0;
}
