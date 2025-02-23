#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		std::cout << b2.getName() << std::endl;
		std::cout << b2.getGrade() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat copy assignment operator test **" << std::endl;
		Bureaucrat b1;
		Bureaucrat b2("Test", 42);
		b1 = b2;
		b1 = b1;
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
	}
	std::cout << std::endl;

	{
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
	}
	std::cout << std::endl;

	{
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

	{
		std::cout << "** Bureaucrat signForm method test **" << std::endl;
		Bureaucrat b1("Low", 150);
		Bureaucrat b2("High", 1);
		Form test1("test", 100, 100);
		b1.signForm(test1);
		b2.signForm(test1);
	}
	std::cout << std::endl;

	{
		std::cout << "** Form default constructor test **" << std::endl;
		Form f;
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;

	}
	std::cout << std::endl;

	{
		std::cout << "** Form parameter constructor test **" << std::endl;
		Form f("John", 42, 21);
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		try
		{
			Form f1("Test", 0, 21);
		}
		catch (const Form::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f2("Test", 200, 21);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f3("Test", 42, 0);
		}
		catch (const Form::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f4("Test", 42, 200);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "** Form copy constructor test **" << std::endl;
		Form f1;
		Form f2 = f1;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;

	}
	std::cout << std::endl;

	{
		std::cout << "** Form copy assignment operator test **" << std::endl;
		Form f1;
		Form f2("Test", 42, 21);
		f1 = f2;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** Form beSigned method test **" << std::endl;
		try
		{
			Bureaucrat b1("Low", 150);
			Bureaucrat b2("High", 1);
			Form f("Test", 100, 100);
			f.beSigned(b2);
			f.beSigned(b1);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
