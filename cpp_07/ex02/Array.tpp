#include <iostream>

template <typename T>
Array<T>::Array() : mData(NULL), mSize(0)
{
	std::cout << "Array default constructor" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor" << std::endl;
	delete[] mData;
}

template <typename T>
Array<T>::Array(unsigned n) : mSize(n)
{
	std::cout << "Array unsigned int constructor" << std::endl;
	mData = new T[mSize]();
}

template <typename T>
Array<T>::Array(const Array& other) : mSize(other.mSize)
{
	std::cout << "Array copy constructor" << std::endl;
	if (mSize != 0)
	{
		mData = new T[mSize];
		for (unsigned i = 0; i < mSize; ++i)
			mData[i] = other.mData[i];
	}
	else
		mData = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Array copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	delete[] mData;
	mSize = other.mSize;
	if (mSize != 0)
	{
		mData = new T[mSize];
		for (unsigned i = 0; i < mSize; ++i)
			mData[i] = other.mData[i];
	}
	else
		mData = NULL;
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned i)
{
	if (i >= mSize)
		throw std::out_of_range("Index out of bounds");
	return mData[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned i) const
{
	if (i >= mSize)
		throw std::out_of_range("Index out of bounds");
	return mData[i];
}

template <typename T>
unsigned Array<T>::size() const
{
	return mSize;
}
