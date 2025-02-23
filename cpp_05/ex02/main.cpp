#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
			Bureaucrat b1("Doe", 200);
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
		Bureaucrat b2("Test", 120);
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

	{
		std::cout << "** Bureaucrat signForm method test **" << std::endl;
		Bureaucrat b1("Low", 150);
		Bureaucrat b2("High", 1);
		PresidentalPardonForm test1;
		RobotomyRequestForm test2;
		ShrubberyCreationForm test3;
		b1.signForm(test1);
		b2.signForm(test1);
		b1.signForm(test2);
		b2.signForm(test2);
		b1.signForm(test3);
		b2.signForm(test3);
	}
	std::cout << std::endl;

	{
		std::cout << "** Bureaucrat executeForm method test **" << std::endl;
		Bureaucrat b1("Low", 150);
		Bureaucrat b2("High", 1);
		PresidentalPardonForm test1;
		RobotomyRequestForm test2;
		ShrubberyCreationForm test3;
		b1.executeForm(test1);
		b1.executeForm(test2);
		b1.executeForm(test3);
		b2.executeForm(test1);
		b2.executeForm(test2);
		b2.executeForm(test3);
		b2.signForm(test1);
		b2.signForm(test2);
		b2.signForm(test3);
		b2.executeForm(test1);
		b2.executeForm(test2);
		b2.executeForm(test3);
		b1.executeForm(test1);
		b1.executeForm(test2);
		b1.executeForm(test3);
	}
	std::cout << std::endl;

	{
		std::cout << "** PresidentalPardonForm default constructor test **" << std::endl;
		PresidentalPardonForm f;
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** PresidentalPardonForm string constructor test **" << std::endl;
		PresidentalPardonForm f("Test");
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** PresidentalPardonForm copy constructor test **" << std::endl;
		PresidentalPardonForm f1("Test");
		PresidentalPardonForm f2 = f1;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** PresidentalPardonForm copy assignment operator test**" << std::endl;
		PresidentalPardonForm f1("Test");
		PresidentalPardonForm f2;
		f2 = f1;
		f2 = f2;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** PresidentalPardonForm execute method test **" << std::endl;
		try
		{
			Bureaucrat b("High", 1);
			PresidentalPardonForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Low", 150);
			PresidentalPardonForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b1("High", 1);
			Bureaucrat b2("Low", 150);
			PresidentalPardonForm f;
			f.beSigned(b1);
			f.execute(b2);
		}
		catch (const AForm::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}

		Bureaucrat b("High", 1);
		PresidentalPardonForm f;
		f.beSigned(b);
		f.execute(b);
	}
	std::cout << std::endl;

	///////////////////////
	{
		std::cout << "** RobotomyRequestForm default constructor test **" << std::endl;
		RobotomyRequestForm f;
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** RobotomyRequestForm string constructor test **" << std::endl;
		RobotomyRequestForm f("Test");
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** RobotomyRequestForm copy constructor test **" << std::endl;
		RobotomyRequestForm f1("Test");
		RobotomyRequestForm f2 = f1;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** RobotomyRequestForm copy assignment operator test**" << std::endl;
		RobotomyRequestForm f1("Test");
		RobotomyRequestForm f2;
		f2 = f1;
		f2 = f2;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** RobotomyRequestForm execute method test **" << std::endl;
		try
		{
			Bureaucrat b("High", 1);
			RobotomyRequestForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Low", 150);
			RobotomyRequestForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b1("High", 1);
			Bureaucrat b2("Low", 150);
			RobotomyRequestForm f;
			f.beSigned(b1);
			f.execute(b2);
		}
		catch (const AForm::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}

		Bureaucrat b("High", 1);
		RobotomyRequestForm f;
		f.beSigned(b);
		f.execute(b);
	}
	std::cout << std::endl;

	{
		std::cout << "** ShrubberyCreationForm default constructor test **" << std::endl;
		ShrubberyCreationForm f;
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** ShrubberyCreationForm string constructor test **" << std::endl;
		ShrubberyCreationForm f("Test");
		std::cout << f.getName() << std::endl;
		std::cout << f.getSignGrade() << std::endl;
		std::cout << f.getExecuteGrade() << std::endl;
		std::cout << f.getIsSigned() << std::endl;
		std::cout << f.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** ShrubberyCreationForm copy constructor test **" << std::endl;
		ShrubberyCreationForm f1("Test");
		ShrubberyCreationForm f2 = f1;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** ShrubberyCreationForm copy assignment operator test**" << std::endl;
		ShrubberyCreationForm f1("Test");
		ShrubberyCreationForm f2;
		f2 = f1;
		f2 = f2;
		std::cout << f2.getName() << std::endl;
		std::cout << f2.getSignGrade() << std::endl;
		std::cout << f2.getExecuteGrade() << std::endl;
		std::cout << f2.getIsSigned() << std::endl;
		std::cout << f2.getTarget() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** ShrubberyCreationForm execute method test **" << std::endl;
		try
		{
			Bureaucrat b("High", 1);
			ShrubberyCreationForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Low", 150);
			ShrubberyCreationForm f;
			f.execute(b);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b1("High", 1);
			Bureaucrat b2("Low", 150);
			ShrubberyCreationForm f;
			f.beSigned(b1);
			f.execute(b2);
		}
		catch (const AForm::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}

		Bureaucrat b("High", 1);
		ShrubberyCreationForm f;
		f.beSigned(b);
		f.execute(b);
	}
	std::cout << std::endl;

	{
		std::cout << "** Polymorphism test **" << std::endl;
		Bureaucrat b("High", 1);
		AForm *f1 = new ShrubberyCreationForm("T1");
		AForm *f2 = new RobotomyRequestForm("T2");
		AForm *f3 = new PresidentalPardonForm("T3");
		f1->beSigned(b);
		f2->beSigned(b);
		f3->beSigned(b);
		f1->execute(b);
		f2->execute(b);
		f3->execute(b);

		b.executeForm(*f1);
		b.executeForm(*f2);
		b.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;
	}
	std::cout << std::endl;

	return 0;
}
