#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void)
{
	int n = std::rand() % 3;
	if (n == 0)
		return new A();
	if (n == 1)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
	}
	catch (const std::exception& e) {}
}
