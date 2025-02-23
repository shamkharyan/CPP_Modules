#ifndef SHRUBBERY_CREATION_FORM_HPP_
#define SHRUBBERY_CREATION_FORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
    const std::string mTarget;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    const std::string& getTarget() const;
    void execute(const Bureaucrat& executor) const;
};

#endif //SHRUBBERY_CREATION_FORM_HPP_
