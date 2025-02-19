#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), mTarget("Default")
{
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), mTarget(target)
{
    std::cout << "ShrubberyCreationForm string constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), mTarget(other.mTarget)
{
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    std::fstream file;
    std::string name;

    checkExecute(executor);
    name = mTarget + "_shrubbery";
    file.open(name, std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Can't open file");
    
    file << "      # #### ####               " << std::endl;
    file << "     ### \\/#|### |/####        " << std::endl;
    file << "    ##\\/#/ \\||/##/_/##/_#     " << std::endl;
    file << "  ###  \\/###|/ \\/ # #####     " << std::endl;
    file << " ##_\\_#\\_\\## | #/###_/_####  " << std::endl;
    file << "## #### # \\ #| /  #### ##/##   " << std::endl;
    file << " __#_--###`  |{,###---###-~     " << std::endl;
    file << "          \\ }{                 " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "      ejm  {{}                  " << std::endl;
    file << "     , -=-~{ .-^- _             " << std::endl;
    file << "           `}                   " << std::endl;
    file << "            {                   " << std::endl;
	file.close();
}


