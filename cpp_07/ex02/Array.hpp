#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template <typename T>
class Array
{
public:
	Array();
	explicit Array(unsigned n);
	~Array();
	Array(const Array& other);
	Array& operator=(const Array& other);
	T& operator[](unsigned i);
	unsigned size() const;
private:
	T* mData;
	unsigned mSize;
};

#include "Array.tpp"

#endif //ARRAY_HPP_
