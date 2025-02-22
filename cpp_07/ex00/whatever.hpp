#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	return (a < b)? a : b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b)? a : b;
}

#endif //WHATEVER_HPP_
