#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : mName("Default"), mSignGrade(100), mExecuteGrade(100), mIsSigned(false)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string& name, std::size_t signGrade, std::size_t executeGrade)
	: mName(name), mSignGrade(signGrade), mExecuteGrade(executeGrade), mIsSigned(false)
{
	std::cout << "Form parameter constructor" << std::endl;
	if (signGrade < 1)
		throw GradeTooHighException("SignGrade is to High");
	if (signGrade > 150)
		throw GradeTooLowException("SignGrade is to Low");
	if (executeGrade < 1)
		throw GradeTooHighException("ExecuteGrade is to High");
	if (executeGrade > 150)
		throw GradeTooLowException("ExecuteGrade is to Low");
}

Form::Form(const Form& other) : 
	mName(other.mName), mSignGrade(other.mSignGrade), mExecuteGrade(other.mExecuteGrade), mIsSigned(other.mIsSigned)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	mIsSigned = other.mIsSigned;
	return (*this);
}

const std::string& Form::getName() const
{
	return mName;
}

std::size_t Form::getSignGrade() const
{
	return mSignGrade;
}

std::size_t Form::getExecuteGrade() const
{
	return mExecuteGrade;
}

bool Form::getIsSigned() const
{
	return mIsSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > mSignGrade)
		throw GradeTooLowException("Bureaucrat can't sign this form, to low grade");
	mIsSigned = true;
}

Form::GradeTooHighException::GradeTooHighException()
{
	mMsg = "Grade is to High";
}

Form::GradeTooHighException::GradeTooHighException(const char *msg)
{
	mMsg = msg;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return mMsg;
}

Form::GradeTooLowException::GradeTooLowException()
{
	mMsg = "Grade is to Low";
}

Form::GradeTooLowException::GradeTooLowException(const char *msg)
{
	mMsg = msg;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return mMsg;
}

std::ostream& operator<<(std::ostream& o, const Form& obj)
{
	o << "Name: " << obj.getName() << std::endl;
	o << "SignGrade: " << obj.getSignGrade() << std::endl;
	o << "ExecuteGrade: " << obj.getExecuteGrade() << std::endl;
	o << "isSigned: " << obj.getIsSigned() << std::endl;
	return o; 
}