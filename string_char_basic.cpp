#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int main() {

	std::shared_ptr<char[]> outDigest(new char[256]);
	string str = "hey";
	memcpy(outDigest.get(), str.c_str(), str.size());
	cout << "val:" << outDigest.get() << " size:" << strlen(outDigest.get()) << std::endl;


	return 0;
}
