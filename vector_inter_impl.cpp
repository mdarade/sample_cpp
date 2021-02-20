#include <iostream>
#include <exception>
#include <cmath>
#include <cstring>

using namespace std;

template <typename T>
class my_vec {
private:
	T *data_{nullptr};
	uint64_t size_{0};
	uint64_t capacity_{0};
public:
	my_vec(uint64_t sz, T val) {
		data_ = nullptr;
		size_ = sz;
		_resize();
		auto tracker = data_;
		for (uint64_t i=0; i<size_; i++) {
			*tracker++ = val;
		}
	}

	~my_vec() {
		delete data_;
	}

	void _resize() {
		capacity_ = pow(2, (size_/2)+1);
		cout << "new capacity is " << capacity_ << std::endl;
		T* new_data_ = new T(capacity_);

		if (data_ == nullptr)  {
			data_ = new_data_;
			return;
		}

		cout << "rebased" << std::endl;
		auto src = data_;
		auto dest = new_data_;
		for(uint64_t i=0; i<size_; i++) {
			*dest++ = *src++;
		}
		delete data_;
		data_ = new_data_;
	}
	
	void push_back(T val) {
		if (size_ >= capacity_)
			_resize();
		data_[size_++] = val;
	}


	T operator[](const uint64_t& index) {
		if (index >= size_)
			throw std::runtime_error("out of bounds");
		return data_[index];
	}
};

int main() {

	cout << "+++++++++++int test ++++++++"<< std::endl;
	my_vec<int> vc(3, 0);
	cout << vc[0] << std::endl;
	vc.push_back(1);
	vc.push_back(2);
	try {
		cout << vc[4] << std::endl;
	} catch (std::exception& t) {
		cout << t.what() << std::endl;
	}

	cout << "++++++char test ++++++++++" << std::endl;

	my_vec<char> vc2(3, 'a');
	cout << vc2[0] << std::endl;
	vc2.push_back('b');
	vc2.push_back('c');
	try {
		cout << vc2[4] << std::endl;
	} catch (std::exception& t) {
		cout << t.what() << std::endl;
	}
	return 0;
}

