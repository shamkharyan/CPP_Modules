#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

int main()
{
	std::cout << "** Animal array test **" << std::endl;
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
    {
        delete animals[i];
    }
	std::cout << std::endl;

	std::cout << "** Brain default constructor test **" << std::endl;
	Brain* b = new Brain();
	std::cout << std::endl;

	std::cout << "** Brain addIdea method test **" << std::endl;
	b->addIdea("Some Idea");
	for (int i = 0; i < 50; ++i)
		b->addIdea("Another Idea");
    for (int i = 50; i < 99; ++i)
        b->addIdea("Some Another Idea");
    b->addIdea("Cant add idea anymore");
    std::cout << std::endl;

    std::cout << "** Brain getIdea method test **" << std::endl;
    for (unsigned i = 0; i < 100; ++i)
        std::cout << b->getIdea(i) << std::endl;
    try
    {
        b->getIdea(-1);
    }
    catch(const std::exception& e)
    {
        std::cout << "Wrong index" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "** Brain getSize method test **" << std::endl;
    std::cout << b->getSize();
    std::cout << std::endl;

    std::cout << "** Brain copy constructor test **" << std::endl;
    Brain *b_copy = new Brain(*b);
    delete b;
    for (unsigned i = 0; i < 100; ++i)
        std::cout << b_copy->getIdea(i) << std::endl;
    std::cout << std::endl;

    std::cout << "** Brain copy assignment operator test **" << std::endl;
    Brain *b2 = new Brain();
    b2->addIdea("Genius Idea");
    *b_copy = *b2;
    *b_copy = *b_copy;
    delete b2;
    std::cout << b_copy->getIdea(0);
    std::cout << std::endl;

    std::cout << "** Brain destructor test **" << std::endl;
    delete b_copy;
    std::cout << std::endl;
    
    std::cout << "** Dog getBrain method and default constructor test **" << std::endl;
    Dog *dog1 = new Dog();
    Brain* brain1 = dog1->getBrain();
    brain1->addIdea("Hello");
    brain1->addIdea("GroveStreet4Life");
    brain1->addIdea("I have two number 9...");
    brain1->addIdea("OOO MY DAWG");
    std::cout << std::endl;

    std::cout << "** Dog copy constructor test **" << std::endl;
    Dog *dog2 = new Dog(*dog1);
    Brain* brain2 = dog2->getBrain();
    brain2->addIdea("Ballas sucks");
    std::cout << brain2->getIdea(0) << std::endl;
    std::cout << brain2->getIdea(4) << std::endl;
    std::cout << std::endl;

    std::cout << "** Dog copy assignment operator test **" << std::endl;
    *dog2 = *dog1;
    *dog2 = *dog2;
    dog2->getBrain()->addIdea("Bark...");
    std::cout << dog2->getBrain()->getIdea(4) << std::endl;
    std::cout << std::endl;

    std::cout << "** Dog destructor test **" << std::endl;
    delete dog1;
    delete dog2;
    std::cout << std::endl;

    std::cout << "** Cat getBrain method and default constructor test **" << std::endl;
    Cat *cat1 = new Cat();
    Brain* brain3 = cat1->getBrain();
    brain3->addIdea("Hello");
    brain3->addIdea("GroveStreet4Life");
    brain3->addIdea("I have two number 9...");
    brain3->addIdea("OOO MY DAWG");
    std::cout << std::endl;

    std::cout << "** Cat copy constructor test **" << std::endl;
    Cat *cat2 = new Cat(*cat1);
    Brain* brain4 = cat2->getBrain();
    brain4->addIdea("Ballas sucks");
    std::cout << brain4->getIdea(0) << std::endl;
    std::cout << brain4->getIdea(4) << std::endl;
    std::cout << std::endl;

    std::cout << "** Cat copy assignment operator test **" << std::endl;
    *cat2 = *cat1;
    *cat2 = *cat2;
    cat2->getBrain()->addIdea("Meow...");
    std::cout << cat2->getBrain()->getIdea(4) << std::endl;
    std::cout << std::endl;

    std::cout << "** Cat destructor test **" << std::endl;
    delete cat1;
    delete cat2;
    std::cout << std::endl;

    return (0);
}
