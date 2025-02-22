#include "Animal.h"
#include <string>
#include <iostream>

Animal::Animal() : mType("default")
{
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const std::string& type) : mType(type)
{
    std::cout << "Animal string constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal& animal) : mType(animal.mType)
{
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal copy assign operator" << std::endl;
    if (this == &animal)
        return (*this);
    mType = animal.mType;
    return (*this);
}

std::string Animal::getType() const
{
    return mType;
}
