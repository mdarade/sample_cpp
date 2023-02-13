#include <iostream>

using namespace std;


bool ora () {
	auto ret1 = true;
	auto ret2 = false;
	return ret1 || ret2;
}

bool anda () {
	auto ret1 = true;
	auto ret2 = false;
	return ret1 && ret2;

}

int main() {
	//if (ora()) {
	if (anda()) {
		cout << "got true";
	} else {
		cout << "got false";
	} 
	return 0;
}


	
