#include <iostream>
#include "vector.h"

namespace vec {

template <typename T>
Vector<T>::Vector(const unsigned int size) {
	this->data = new T[size];
	this->sz = size;
}

template <typename T>
Vector<T>::Vector(const unsigned int size, const T& val) {
	this->data = new T[size];
	this->sz = size;
	for (int i=0; i<size; i++) {
		this->data[i] = val;
	}
}

template<typename T>
Vector<T>::~Vector(){
	delete[] this->data;
}

template< typename T >
inline T& Vector<T>::operator[](const unsigned int i) {
	return this->data[i];
}

template< typename T >
inline T Vector<T>::operator[](const unsigned int i) const {
	return this->data[i];
}

template<typename T>
unsigned int Vector<T>::size(){
	return this->sz;
}

template<typename T>
void Vector<T>::push_back(const T& val){
	unsigned int prev_sz = this->sz;
	T* prev_data = new T[prev_sz];
	for(int i=0; i<prev_sz; i++) prev_data[i] = this->data[i];
	delete[] this->data;

	this->sz = prev_sz + 1;
	this->data = new T[sz];
	for(int i=0; i<prev_sz; i++) this->data[i] = prev_data[i];
	this->data[prev_sz] = val;
	delete[] prev_data;
}

Vector<int> zeros(const unsigned int size){
	return Vector<int>(size, 0);
}

Vector<int> ones(const unsigned int size){
	return Vector<int>(size, 1);
}

template<typename T>
Vector<T> arange(const T start, const T stop, const T step) {
	const unsigned int size = (stop - start) / step + 1;
	Vector<T> x = Vector<T>(size);
	for (int i=0; i<size; i++) {
		x.data[i] = start + i * step;
	}
	return x;
}

template<typename T>
T Vector<T>::mean() {
	const unsigned int size = this->sz;
	return this->sum() / size;
}

template<typename T>
T Vector<T>::sum() {
	T ret = 0.0;
	const unsigned int size = this->sz;
	for (int i=0; i<size; i++) {
		ret += this->data[i];
	}
	return ret;
}

template<typename T>
T Vector<T>::max() {
	const unsigned int size = this->sz;
	T ret = this->data[0];
	for (int i=1; i<size; i++) {
		if (ret < this->data[i]) {
			ret = this->data[i];
		}
	}
	return ret;
}

template<typename T>
T Vector<T>::min() {
	const unsigned int size = this->sz;
	T ret = this->data[0];
	for (int i=1; i<size; i++) {
		if (ret > this->data[i]) {
			ret = this->data[i];
		}
	}
	return ret;
}

}

int main() {
	const unsigned int size = 16;
	vec::Vector<int> x = vec::Vector<int>(size);
	std::cout << *x.data << std::endl;

	const int val = 5;
	vec::Vector<int> y = vec::Vector<int>(size, val);
	std::cout << *y.data << std::endl;

	vec::Vector<int> zeros = vec::zeros(size);
	std::cout << *zeros.data << std::endl;

	vec::Vector<int> ones = vec::ones(size);
	std::cout << *ones.data << std::endl;

	std::cout << ones.size() << std::endl;

	vec::Vector<double> range = vec::arange(0., 10., 1.);
	std::cout << range.data[0] << std::endl;
	std::cout << range.data[1] << std::endl;
	std::cout << range[1] << std::endl;
	std::cout << range.data[2] << std::endl;
	std::cout << range[2] << std::endl;

	std::cout << "Hello" << std::endl;
	std::cout << range.max() << std::endl;
	std::cout << range.min() << std::endl;
	std::cout << range.mean() << std::endl;
	std::cout << range.sum() << std::endl;
	range.push_back(20.1);
	std::cout << range[11] << std::endl;
	return 0;
};
