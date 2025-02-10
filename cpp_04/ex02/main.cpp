#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

int main()
{
    Animal *animals[10];

    for (unsigned i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        animals[i]->makeSound();
    }

    for (unsigned i = 0; i < 10; ++i)
        delete animals[i];

    Dog *dog1 = new Dog();
    Brain* brain1 = dog1->getBrain();

    brain1->addIdea("Hello");
    brain1->addIdea("GroveStreet4Life");
    brain1->addIdea("I have two number 9...");
    brain1->addIdea("OOO MY DAWG");

    Dog *dog2 = new Dog(*dog1);
    delete dog1;

    Brain* brain2 = dog2->getBrain();
    brain2->addIdea("Ballas sucks");
    std::cout << brain2->getIdea(4) << std::endl;
    delete dog2;

    Cat *cat1 = new Cat();
    Brain* brain3 = cat1->getBrain();

    brain3->addIdea("Hello");
    brain3->addIdea("GroveStreet4Life");
    brain3->addIdea("I have two number 9...");
    brain3->addIdea("OOO MY DAWG");

    Cat *cat2 = new Cat(*cat1);
    delete cat1;

    Brain* brain4 = cat2->getBrain();
    brain4->addIdea("Ballas sucks");
    std::cout << brain4->getIdea(4) << std::endl;
    delete cat2;

    return (0);
}