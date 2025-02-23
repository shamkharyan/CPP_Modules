#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "** Intern default constructor test **" << std::endl;
		Intern i;
	}
	std::cout << std::endl;

	{
		std::cout << "** Intern copy constructor test **" << std::endl;
		Intern i1;
		Intern i2 = i1;
	}
	std::cout << std::endl;

	{
		std::cout << "** Intern copy assignment operator test **" << std::endl;
		Intern i1;
		Intern i2;
		i2 = i1;
		i1 = i1;
	}
	std::cout << std::endl;

	{
		std::cout << "** Intern makeForm method test **" << std::endl;
		Intern i;
		Bureaucrat b("High", 1);
		AForm *f;

		f = i.makeForm("PresidentalPardonForm", "Test1");
		if (f)
		{
			f->beSigned(b);
			f->execute(b);
			delete f;
		}

		f = i.makeForm("RobotomyRequestForm", "Test2");
		if (f)
		{
			f->beSigned(b);
			f->execute(b);
			delete f;
		}

		f = i.makeForm("ShrubberyCreationForm", "Test3");
		if (f)
		{
			f->beSigned(b);
			f->execute(b);
			delete f;
		}

		f = i.makeForm("SomeRandomText", "Test4");
		std::cout << f << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
