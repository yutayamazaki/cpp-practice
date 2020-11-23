#include <iostream>
#include <string>

namespace vec {

template<typename T>
class Vector {
public:
	T* data; // ベクトルの各要素を格納するための動的配列のポインタ変数
private:
	unsigned int sz; // 配列のサイズ
public:
	Vector();
	Vector(const unsigned int size); // コンストラクタ
	Vector(const unsigned int size, const T& val); // コンストラクタ
	~Vector(); // デストラクタ

  	T& operator[]( const unsigned int i );
  	T  operator[]( const unsigned int i ) const;

	unsigned int size();
  	void push_back( const T& val );

	T max();
	T min();
	T abs();
	T mean();
	T sum();
};

Vector<int> zeros(const unsigned int size);
Vector<int> ones(const unsigned int size);
template <typename T>
Vector<T> arange(const T start, const T stop, const T step);

};
