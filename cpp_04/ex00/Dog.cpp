#include "Animal.h"
#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog copy assign operator" << std::endl;
    if (this == &dog)
        return (*this);
    Animal::operator=(dog);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bark..." << std::endl;
}
