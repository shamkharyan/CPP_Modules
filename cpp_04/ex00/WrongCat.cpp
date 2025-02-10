#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    std::cout << "WrongCat copy assign operator" << std::endl;
    if (this == &wrongCat)
        return (*this);
    WrongAnimal::operator=(wrongCat);
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}