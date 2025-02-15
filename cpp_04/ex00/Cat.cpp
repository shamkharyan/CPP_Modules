#include "Animal.h"
#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat copy assign operator" << std::endl;
    if (this == &cat)
        return (*this);
    Animal::operator=(cat);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}
