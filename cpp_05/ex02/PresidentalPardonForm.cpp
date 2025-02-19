#include "PresidentalPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm("PresidentalPardonForm", 25, 5), mTarget("Default")
{
    std::cout << "PresidentalPardonForm default constructor" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(const std::string& target) : AForm("PresidentalPardonForm", 25, 5), mTarget(target)
{
    std::cout << "PresidentalPardonForm string constructor" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm& other) : AForm(other), mTarget(other.mTarget)
{
    std::cout << "PresidentalPardonForm copy constructor" << std::endl;
}

PresidentalPardonForm::~PresidentalPardonForm()
{
    std::cout << "PresidentalPardonForm destructor" << std::endl;
}

PresidentalPardonForm& PresidentalPardonForm::operator=(const PresidentalPardonForm& other)
{
    std::cout << "PresidentalPardonForm copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

const std::string& PresidentalPardonForm::getTarget() const
{
    return mTarget;
}

void PresidentalPardonForm::execute(const Bureaucrat& executor) const
{
    checkExecute(executor);
    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
