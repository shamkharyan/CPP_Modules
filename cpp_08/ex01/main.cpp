#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	{
		std::cout << "** AddNumber test **" << std::endl;
		Span sp(5);
		sp.addNumber(10);
		sp.addNumber(20);
		assert(sp.getSize() == 2);
		std::cout << "testAddNumber passed\n";
	}
	std::cout << std::endl;

	{
		std::cout << "** StorageOverflow test **" << std::endl;
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try
		{
			sp.addNumber(4);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Shortest and longest span test **" << std::endl;
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** No span test **" << std::endl;
		Span sp(5);
		try
		{
			sp.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		Span sp2(5);
		try
		{
			sp2.addNumber(10);
			sp.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Fill test **" << std::endl;
		std::srand(std::time(NULL));
		Span sp(10);
		sp.fill(rand());
    	std::cout << sp.getSize() << std::endl;
		std::cout << sp.getCapacity() << std::endl;

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** tests for big dataset **" << std::endl;
		std::srand(std::time(NULL));
		for (int i = 0; i < 10; ++i)
		{
			Span sp(10000);
			sp.fill(rand());
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
