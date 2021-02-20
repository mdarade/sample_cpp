#include <iostream>

using namespace std;

int main() {

	int a=0, b=0;

	if (a || b)
		cout << "screwed" << std::endl;

	if (a and b)
		cout << "not screwed" << std::endl;

	return 0;
}
	
