#ifndef ROBOTOMY_REQUEST_FORM_HPP_
#define ROBOTOMY_REQUEST_FORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    const std::string mTarget;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    const std::string& getTarget() const;
    void execute(const Bureaucrat& executor) const;
};

#endif //ROBOTOMY_REQUEST_FORM_HPP_
