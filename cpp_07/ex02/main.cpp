#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	{
		std::cout << "** Array default constructor test **" << std::endl;
		Array<int> a;
		Array<float> b;
		Array<std::string> c;
		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Array unsigned int constructor test **" << std::endl;
		Array<int> a(1000);
		Array<float> b(1000);
		Array<std::string> c(10000);
		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;
		std::cout << a[0] << std::endl;
		std::cout << b[10] << std::endl;
		std::cout << c[9999] << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Array copy constructor test **" << std::endl;
		Array<int> a(10);
		std::cout << a.size();
		for (int i = 0; i < 10; ++i)
			a[i] = i;
		Array<int> aa = a;
		std::cout << aa.size();
		for (int i = 0; i < 10; ++i)
			std::cout << aa[i] << std::endl;
		Array<float> b(10);
		for (int i = 0; i < 10; ++i)
			b[i] = i;
		Array<float> bb = b;
		for (int i = 0; i < 10; ++i)
			std::cout << bb[i] << std::endl;
		Array<std::string> c(10);
		for (int i = 0; i < 10; ++i)
			c[i] = std::to_string(i);
		Array<std::string> cc = c;
		for (int i = 0; i < 10; ++i)
			std::cout << cc[i] << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Array copy assignment operator test **" << std::endl;
		Array<int> a(10);
		std::cout << a.size() << std::endl;
		for (int i = 0; i < 10; ++i)
			a[i] = i;
		Array<int> aa(20);
		aa = a;
		std::cout << aa.size() << std::endl;
		for (int i = 0; i < 10; ++i)
			std::cout << aa[i] << std::endl;
		Array<float> b(10);
		for (int i = 0; i < 10; ++i)
			b[i] = i;
		Array<float> bb(20);
		bb = b;
		for (int i = 0; i < 10; ++i)
			std::cout << bb[i] << std::endl;
		Array<std::string> c(10);
		for (int i = 0; i < 10; ++i)
			c[i] = std::to_string(i);
		Array<std::string> cc(20);
		cc = c;
		for (int i = 0; i < 10; ++i)
			std::cout << cc[i] << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Array operator[] test **" << std::endl;
		Array<int> a;
		try
		{
			a[0];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		Array<int> b(20);
		b[5] = 42;
		std::cout << b[5] << std::endl;
		try
		{
			b[-1];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			b[30];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		const Array<int> ca(5);
		std::cout << ca[0] << std::endl;
	}
	return 0;
}
