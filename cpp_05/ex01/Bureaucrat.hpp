#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include "Form.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string mName;
	std::size_t mGrade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, std::size_t grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string& getName() const;
	std::size_t getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;

	class GradeTooHighException : std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP_
