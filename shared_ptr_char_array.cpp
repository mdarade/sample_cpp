#include <iostream>
#include <memory>
#include<cstring>

using namespace std;


int main() {
	
	shared_ptr<char> sptr(new char[10], std::default_delete<char[]>());
	cout << sptr.use_count() << endl;
	char* bufp = sptr.get();
	std::memcpy(bufp, "mahaveer", 8);
	cout << sptr.use_count() << endl;
	cout << bufp << endl;

	return 0;
}

