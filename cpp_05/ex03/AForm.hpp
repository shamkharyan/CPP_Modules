#ifndef AAFORM_HPP_
#define AAFORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string mName;
	const std::size_t mSignGrade;
	const std::size_t mExecuteGrade;
	bool mIsSigned;
	AForm();
protected:
	void checkExecute(const Bureaucrat& executor) const;
public:
	virtual ~AForm();
	AForm(const std::string& name, std::size_t signGrade, std::size_t executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	const std::string& getName() const;
	std::size_t getSignGrade() const;
	std::size_t getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;

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

	class FormNotSignedException : std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& obj);

#endif //AAFORM_HPP_
