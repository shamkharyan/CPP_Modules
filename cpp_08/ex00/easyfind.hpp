#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <algorithm>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw() { return "Element not found in container"; }
};

template <typename T>
typename T::iterator easyfind(T& c, int n)
{
	typename T::iterator it = std::find(c.begin(), c.end(), n);
	if (it == c.end())
		throw NotFoundException();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& c, int n)
{
	typename T::const_iterator it = std::find(c.begin(), c.end(), n);
	if (it == c.end())
		throw NotFoundException();
	return it;
}

#endif //EASYFIND_HPP_
