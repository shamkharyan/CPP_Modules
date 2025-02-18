#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : mName("Default"), mGrade(100)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const std::size_t& grade) : mName(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	mGrade = grade;
	std::cout << "Bureaucrat parameter constructor" << std::endl;
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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (o);
}

