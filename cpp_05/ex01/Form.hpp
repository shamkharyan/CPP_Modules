#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string mName;
	const std::size_t mSignGrade;
	const std::size_t mExecuteGrade;
	bool mIsSigned;
public:
	Form();
	~Form();
	Form(const std::string& name, std::size_t signGrade, std::size_t executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	const std::string& getName() const;
	std::size_t getSignGrade() const;
	std::size_t getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : std::exception
	{
	private:
		const char *mMsg;
	public:
		GradeTooHighException();
		GradeTooHighException(const char *msg);
		const char *what() const throw();
	};

	class GradeTooLowException : std::exception
	{
	private:
		const char *mMsg;
	public:
		GradeTooLowException();
		GradeTooLowException(const char *msg);
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Form& obj);

#endif //FORM_HPP_