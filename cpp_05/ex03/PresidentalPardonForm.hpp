#ifndef PRESIDENTAL_PARDON_FORM_HPP_
#define PRESIDENTAL_PARDON_FORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentalPardonForm : public AForm
{
private:
    const std::string mTarget;
public:
    PresidentalPardonForm();
    PresidentalPardonForm(const std::string& target);
    ~PresidentalPardonForm();
    PresidentalPardonForm(const PresidentalPardonForm& other);
    PresidentalPardonForm& operator=(const PresidentalPardonForm& other);
    const std::string& getTarget() const;
    void execute(const Bureaucrat& executor) const;
};

#endif //PRESIDENTAL_PARDON_FORM_HPP_
