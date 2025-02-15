#include "WrongAnimal.h"
#include "WrongDog.h"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
    std::cout << "WrongDog default constructor" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor" << std::endl;
}

WrongDog::WrongDog(const WrongDog& wrongDog) : WrongAnimal(wrongDog)
{
    std::cout << "WrongDog copy constructor" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& wrongDog)
{
    std::cout << "WrongDog copy assign operator" << std::endl;
    if (this == &wrongDog)
        return (*this);
    WrongAnimal::operator=(wrongDog);
    return (*this);
}

void WrongDog::makeSound() const
{
    std::cout << "Wrong Bark..." << std::endl;
}
