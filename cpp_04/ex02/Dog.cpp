#include "Animal.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor" << std::endl;
    mBrain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete mBrain;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor" << std::endl;
    if (dog.mBrain)
        mBrain = new Brain(*dog.getBrain());
    else
        mBrain = NULL;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog copy assign operator" << std::endl;
    if (this == &dog)
        return (*this);
    Animal::operator=(dog);
    delete mBrain;
    if (dog.mBrain)
        mBrain = new Brain(*dog.getBrain());
    else
        mBrain = NULL;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bark..." << std::endl;
}

Brain* Dog::getBrain() const
{
    return mBrain;
}