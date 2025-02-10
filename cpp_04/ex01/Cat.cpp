#include "Animal.h"
#include "Cat.h"
#include "Brain.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor" << std::endl;
    mBrain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
    delete mBrain;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor" << std::endl;
    if (cat.mBrain)
        mBrain = new Brain(*cat.getBrain());
    else
        mBrain = NULL;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat copy assign operator" << std::endl;
    if (this == &cat)
        return (*this);
    Animal::operator=(cat);
    delete mBrain;
    if (cat.mBrain)
        mBrain = new Brain(*cat.getBrain());
    else
        mBrain = NULL;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}

Brain* Cat::getBrain() const
{
    return mBrain;
}