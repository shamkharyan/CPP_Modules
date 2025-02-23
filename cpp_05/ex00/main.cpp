#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "** Bureaucrat default constructor test **" << std::endl;
		Bureaucrat b;
		std::cout << b.getName() << std::endl;
		std::cout << b.getGrade() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat parameter constructor test **" << std::endl;
		Bureaucrat b("John", 42);
		std::cout << b.getName() << std::endl;
		std::cout << b.getGrade() << std::endl;
		try
		{
			Bureaucrat b1("Doe", 0);
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b2("Doe", 200);
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat copy constructor test **" << std::endl;
		Bureaucrat b1;
		Bureaucrat b2 = b1;
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat copy assignment operator test **" << std::endl;
		Bureaucrat b1("Test", 100);
		Bureaucrat b2;
		b2 = b1;
		b2 = b2;
		std::cout << b2.getName() << std::endl;
		std::cout << b2.getGrade() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat incrementGrade method test **" << std::endl;
		try
		{
			Bureaucrat b("Test", 2);
			b.incrementGrade();
			std::cout << b.getGrade() << std::endl;
			b.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat decrementGrade method test **" << std::endl;
		try
		{
			Bureaucrat b("Test", 149);
			b.decrementGrade();
			std::cout << b.getGrade() << std::endl;
			b.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat operator<< test **" << std::endl;
		const Bureaucrat b1;
		Bureaucrat b2("Foo", 21);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
