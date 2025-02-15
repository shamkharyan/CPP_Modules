#include "WrongAnimal.h"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : mType("default")
{
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : mType(type)
{
    std::cout << "WrongAnimal string constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) : mType(wrongAnimal.mType)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal copy assign operator" << std::endl;
    if (this == &wrongAnimal)
        return (*this);
    mType = wrongAnimal.mType;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some WrongAnimal sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return mType;
}
