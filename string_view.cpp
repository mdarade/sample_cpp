#include <iostream>
using namespace std;
#include <string_view>


int main() {
	std::string str = "mahaveer";
	string_view str_view = str;
	cout << str_view << endl;

	return 0;
}
