#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	std::cout << "** Bureaucrat signForm method test **" << std::endl;
	Form test1("test", 150, 150);
	b1.signForm(test1);
	Form test2("test", 1, 1);
	b1.signForm(test2);
	std::cout << std::endl;

	std::cout << "** Form default constructor test **" << std::endl;
	Form f1;
	std::cout << f1.getName() << std::endl;
	std::cout << f1.getSignGrade() << std::endl;
	std::cout << f1.getExecuteGrade() << std::endl;
	std::cout << f1.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "** Form parameter constructor test **" << std::endl;
	Form f2("John", 42, 21);
	std::cout << f2.getName() << std::endl;
	std::cout << f2.getSignGrade() << std::endl;
	std::cout << f2.getExecuteGrade() << std::endl;
	std::cout << f2.getIsSigned() << std::endl;
	try
	{
		Form f22("Test", 0, 21);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form f23("Test", 200, 21);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form f24("Test", 42, 0);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form f25("Test", 42, 200);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Form copy constructor test **" << std::endl;
	Form f3(f1);
	std::cout << f3.getName() << std::endl;
	std::cout << f3.getSignGrade() << std::endl;
	std::cout << f3.getExecuteGrade() << std::endl;
	std::cout << f3.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "** Form copy assignment operator test **" << std::endl;
	f3 = f2;
	f3 = f3;
	std::cout << f3.getName() << std::endl;
	std::cout << f3.getSignGrade() << std::endl;
	std::cout << f3.getExecuteGrade() << std::endl;
	std::cout << f3.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "** Form beSigned method test **" << std::endl;
	try
	{
		Form f4("Test", 150, 150);
		f4.beSigned(b1);
		Form f5("Test", 1, 1);
		f5.beSigned(b1);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Destructors **" << std::endl;

	return 0;
}