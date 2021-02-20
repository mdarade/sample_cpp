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
	my_vec(uint64_t sz, uint64_t val) {
		data_ = nullptr;
		cout << "in constructor" << std::endl;
		size_ = sz;
		_resize();
		for (T i=0; i<size_; i++) {
			data_[i++] = val;
		}
	}

	~my_vec() {
		delete data_;
	}

	void _resize() {
		capacity_ = pow(2, (size_/2)+1);
		cout << "new capacity is " << capacity_ << std::endl;
		T* new_data_ = new T(capacity_);
		::memset(new_data_, capacity_, 0);
		//copy old data
		if (data_ == nullptr)  {
			cout << "1st init" << std::endl;
			data_ = new_data_;
			return;
		}
		cout << "rebased" << std::endl;
		auto src = data_;
		auto dest = new_data_;
		for(T i=0; i<size_; i++) {
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
	my_vec<int> vc(3, 0);
	cout << vc[0] << std::endl;
	cout << vc[1] << std::endl;
	cout << vc[2] << std::endl;
	cout << "abt to push back" << std::endl;
	vc.push_back(9);
	vc.push_back(90);
	cout << "push back complete" << std::endl;
	try {
		cout << vc[4] << std::endl;
	} catch (std::exception& t) {
		cout << t.what() << std::endl;
	}
	cout << "end" << std::endl;
	return 0;
}

