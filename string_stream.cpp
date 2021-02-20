#include <iostream>
#include <sstream>


using namespace std;


int main() {
	std::stringstream os;
	os << "[" << "md" << "]";


	cout << "chars count:" << os.gcount() << endl;
	os << "howdy";
	cout << "chars count:" << os.gcount() << endl;


	cout << os.str() << endl;


	return 0;
}
