#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	try
	{
		std::cout << "** easyfind test on vector<int> **" << std::endl;
		std::vector<int> v(10);
		v[7] = 42;
		const std::vector<int> cv(v);
		std::vector<int>::iterator vi = easyfind(v, 42);
		std::vector<int>::const_iterator cvi = easyfind(cv, 42);
		std::cout << *cvi << std::endl;
		std::cout << *vi << std::endl;
		easyfind(v, 21);
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "** easyfind test on list<int> **" << std::endl;
		std::list<int> l(10);
		*std::next(l.begin(), 7) = 42;
		const std::list<int> cl(l);
		std::list<int>::iterator li = easyfind(l, 42);
		std::list<int>::const_iterator cli = easyfind(cl, 42);
		std::cout << *li << std::endl;
		std::cout << *cli << std::endl;
		easyfind(l, 21);
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "** easyfind test on deque<int> **" << std::endl;
		std::deque<int> d(10);
		*std::next(d.begin(), 7) = 42;
		const std::deque<int> cd(d);
		std::deque<int>::iterator di = easyfind(d, 42);
		std::deque<int>::const_iterator cdi = easyfind(cd, 42);
		std::cout << *di << std::endl;
		std::cout << *cdi << std::endl;
		easyfind(d, 21);
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
