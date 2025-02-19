#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor" << std::endl;
	(void) other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator" << std::endl;
	(void) other;
	return (*this);
}

AForm *Intern::makeForm(const std::string& form, const std::string& target) const
{
	std::string names[] = {
		"PresidentalPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	AForm *forms[] = {
		new PresidentalPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	AForm *returnForm = NULL;

	for (int i = 0; i < 3; ++i)
	{
		if (names[i] == form)
			returnForm = forms[i];
		else
			delete forms[i];
	}

	if (!returnForm)
		std::cout << "No form with name " << form << std::endl;
	else
		std::cout << form << " created" << std::endl;
	return returnForm;
}