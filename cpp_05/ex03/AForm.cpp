#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : mName("Default"), mSignGrade(100), mExecuteGrade(100), mIsSigned(false)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string& name, std::size_t signGrade, std::size_t executeGrade)
	: mName(name), mSignGrade(signGrade), mExecuteGrade(executeGrade), mIsSigned(false)
{
	std::cout << "AForm parameter constructor" << std::endl;
	if (signGrade < 1)
		throw GradeTooHighException("SignGrade is to High");
	if (signGrade > 150)
		throw GradeTooLowException("SignGrade is to Low");
	if (executeGrade < 1)
		throw GradeTooHighException("ExecuteGrade is to High");
	if (executeGrade > 150)
		throw GradeTooLowException("ExecuteGrade is to Low");
}

AForm::AForm(const AForm& other) :
	mName(other.mName), mSignGrade(other.mSignGrade), mExecuteGrade(other.mExecuteGrade), mIsSigned(other.mIsSigned)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	mIsSigned = other.mIsSigned;
	return (*this);
}

const std::string& AForm::getName() const
{
	return mName;
}

std::size_t AForm::getSignGrade() const
{
	return mSignGrade;
}

std::size_t AForm::getExecuteGrade() const
{
	return mExecuteGrade;
}

bool AForm::getIsSigned() const
{
	return mIsSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > mSignGrade)
		throw GradeTooLowException("Bureaucrat can't sign this form, to low grade");
	mIsSigned = true;
}

AForm::GradeTooHighException::GradeTooHighException()
{
	mMsg = "Grade is to High";
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg)
{
	mMsg = msg;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return mMsg;
}

AForm::GradeTooLowException::GradeTooLowException()
{
	mMsg = "Grade is to Low";
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg)
{
	mMsg = msg;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return mMsg;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Bureaucrat can't execute this form, form is not signed";
}

void AForm::checkExecute(const Bureaucrat& executor) const
{
	if (!mIsSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > mExecuteGrade)
		throw AForm::GradeTooLowException("Bureaucrat can't execute this form, to low grade");
}

std::ostream& operator<<(std::ostream& o, const AForm& obj)
{
	o << "Name: " << obj.getName() << std::endl;
	o << "SignGrade: " << obj.getSignGrade() << std::endl;
	o << "ExecuteGrade: " << obj.getExecuteGrade() << std::endl;
	o << "isSigned: " << obj.getIsSigned() << std::endl;
	return o;
}
