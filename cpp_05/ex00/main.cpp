#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "** Bureaucrat default constructor test **" << std::endl;
	Bureaucrat b1;
	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "** Bureaucrat parameter constructor test **" << std::endl;
	Bureaucrat b2("John", 42);
	std::cout << b2.getName() << std::endl;
	std::cout << b2.getGrade() << std::endl;
	try
	{
		Bureaucrat b22("Doe", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b33("Doe", 200);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Bureaucrat copy constructor test **" << std::endl;
	Bureaucrat b3 = b2;
	std::cout << b3.getName() << std::endl;
	std::cout << b3.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "** Bureaucrat copy assignment operator test **" << std::endl;
	b3 = b1;
	b1 = b1;
	std::cout << b3.getName() << std::endl;
	std::cout << b3.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "** Bureaucrat incrementGrade method test **" << std::endl;
	try
	{
		Bureaucrat b4("Test", 2);
		b4.incrementGrade();
		std::cout << b4.getGrade() << std::endl;
		b4.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Bureaucrat decrementGrade method test **" << std::endl;
	try
	{
		Bureaucrat b5("Test", 149);
		b5.decrementGrade();
		std::cout << b5.getGrade() << std::endl;
		b5.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Bureaucrat operator<< test **" << std::endl;
	const Bureaucrat b6;
	Bureaucrat b7("Foo", 21);
	std::cout << b6 << std::endl;
	std::cout << b7 << std::endl;
	std::cout << std::endl;

	std::cout << "** Bureaucrat destructor **" << std::endl;

	return 0;
}