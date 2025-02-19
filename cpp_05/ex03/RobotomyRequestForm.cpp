#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), mTarget("Default")
{
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), mTarget(target)
{
    std::cout << "RobotomyRequestForm string constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), mTarget(other.mTarget)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return mTarget;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    checkExecute(executor);
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << mTarget << " has been robotomized successfull" << std::endl;
    else
        std::cout << "The robotomy on " << mTarget << " failed" << std::endl;
}
