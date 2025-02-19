#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);
	AForm *makeForm(const std::string& form, const std::string& target) const;
};

#endif //INTERN_HPP_