#include <iostream>
using namespace std;

//explicit copy & assignment constructors are required in case of deep copy
//observe int*
//assignment constructor is called only when we are changing already existing object.
//e.g. in below case assignment operator is not called.
//Hello obj2 = obj1;
//Here only copy constructor is called.

class Hello {
public:
	int* data_;
	Hello(int* v) : data_(v) {}
	Hello& operator=(Hello& );
};

Hello& Hello::operator=(Hello& obj) {
	cout << "inside" << std::endl;
	if (this != &obj) {
	       this->data_ = obj.data_;
	} else {
		cout << "why copy same obj?" << std::endl;
	}
	return *this;
}

int main() {
	int src = 10;
#if 0
	Hello obj(&src);
	Hello obj_cp = obj;
	cout << *obj_cp.data_ << std::endl;
	return 0;
#endif

	int dest = 10;
	Hello obj(&src);
	Hello obj_copy(&dest);
	obj = obj;
	obj_copy = obj;
	cout << *obj_copy.data_ << std::endl;
	return 0;
}
