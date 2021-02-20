#include <iostream>
#include <bitset>

using namespace std;

#define BT_SZ 8



class bitmap {

	public:

		bitmap(string bufp) {
			bitmap_ = bufp;
			std::bitset<BT_SZ> bt(bitmap_);
			bt_  = bt;
		}

		std::bitset<BT_SZ> Init() {
			std::bitset<BT_SZ> bt(bitmap_);
			bt_  = bt;
			return bt;
		}

		bool Any() {
			return bt_.any();
		}

		size_t Count() {
			return bt_.count();
		}

		bool All() {
			return bt_.all();
		}

		bool None() {
			return bt_.none();
		}

	private:
		std::bitset<BT_SZ> bt_;
		std::string bitmap_;
};




int main(int argc, char *argv[]) {

	std::string bt_raw("01111110");

	bitmap* obj = new bitmap(bt_raw);

	cout << "is Any bit set:" << obj->Any() << endl;	
	cout << "count of bits set:" << obj->Count() << endl;	

	cout << "is All bit set:" << obj->All() << endl;	
	cout << "is None bit set:" << obj->None() << endl;	

	delete obj;
	return 0;
}
