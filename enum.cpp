#include <iostream>
#include <string>

using namespace std;

enum Error {
	ERR_ONE,
	ERR_TWO,
	ERR_THREE,
};

static const char *Errors[] = {
	"error one",
	"error two",
	"error three"
};

std::string MapError(Error err) {
	return Errors[err];
}

int main(int argc, char *argv[]) {
	std::string str = MapError(ERR_TWO);
	cout << str << endl;
	return 0;	
}
