#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

Span::Span()
{
	std::cout << "Span default constructor" << std::endl;
}

Span::Span(unsigned int capacity)
{
	std::cout << "Span unsigned int constructor" << std::endl;
	mStorage.reserve(capacity);
}

Span::~Span()
{
	std::cout << "Span destructor" << std::endl;
}

Span::Span(const Span& other) : mStorage(other.mStorage)
{
	std::cout << "Span copy constructor" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Span copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	mStorage = other.mStorage;
	return (*this);
}

void Span::addNumber(unsigned n)
{
	if (mStorage.size() == mStorage.capacity())
		throw StorageOverflowException();
	mStorage.push_back(n);
}

void Span::fill()
{
	std::srand(std::time(NULL));

	unsigned sz = mStorage.size();
	unsigned cap = mStorage.capacity();

	while (sz < cap)
	{
		mStorage.push_back(rand());
		++sz;
	}
}

unsigned Span::shortestSpan() const
{
	if (mStorage.capacity() < 2 || mStorage.size() < 2)
		throw NoSpanException();

	unsigned span = std::numeric_limits<unsigned>::max();
	std::vector<int> copy(mStorage);

	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator prev = copy.begin();
	std::vector<int>::iterator curr = copy.begin() + 1;

	while (curr != copy.end())
	{
		if (static_cast<unsigned>(*curr - *prev) < span)
			span = static_cast<unsigned>(*curr - *prev);
		++prev;
		++curr;
	}
	return span;
}

unsigned Span::longestSpan() const
{
	if (mStorage.capacity() < 2 || mStorage.size() < 2)
		throw NoSpanException();

	unsigned max = *std::max_element(mStorage.begin(), mStorage.end());
	unsigned min = *std::min_element(mStorage.begin(), mStorage.end());

	return (max - min);
}

const char *Span::NoSpanException::what() const throw()
{
	return "Storage must have at least 2 elements";
}

const char *Span::StorageOverflowException::what() const throw()
{
	return "Storage is full";
}

unsigned Span::getSize() const { return mStorage.size(); }

unsigned Span::getCapacity() const { return mStorage.capacity(); }


