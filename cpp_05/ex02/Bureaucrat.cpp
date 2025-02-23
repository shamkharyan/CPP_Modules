#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : mName("Default"), mGrade(100)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, std::size_t grade) : mName(name), mGrade(grade)
{
	std::cout << "Bureaucrat parameter constructor" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : mName(other.mName), mGrade(other.mGrade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	mGrade = other.mGrade;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return mName;
}

std::size_t Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::incrementGrade()
{
	if (mGrade == 1)
		throw GradeTooHighException();
	--mGrade;
}

void Bureaucrat::decrementGrade()
{
	if (mGrade == 150)
		throw GradeTooLowException();
	++mGrade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is to High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is to Low";
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << mName << " signed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << mName << " can't sign this form because: ";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << mName << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << mName << " can't execute this form because: ";
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << mName << " can't execute this form because: ";
		std::cout << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (o);
}
