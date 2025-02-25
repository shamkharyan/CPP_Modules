#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>

template <typename T>
void iter(T* arr, std::size_t len, void (*f)(const T&))
{
	for (std::size_t i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void iter(T* arr, std::size_t len, void (*f)(T&))
{
	for (std::size_t i = 0; i < len; ++i)
		f(arr[i]);
}

#endif //ITER_HPP_
