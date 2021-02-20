#include <iostream>
#include <thread>

using namespace std;

class abc { 
	public:
		abc(int value) : var_(value) {}
		void SetVar(int value) { var_ = value; }	
		int GetVar() { return var_; } 
	private:
		int var_{10};
};

int main() {
	abc obj1(1);
	cout << "its:" << obj1.GetVar() << endl;
	return 0;
}

