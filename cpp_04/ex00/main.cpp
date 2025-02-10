#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "WrongDog.h"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wj = new WrongDog();
    const WrongAnimal* wi = new WrongCat();
    std::cout << wj->getType() << " " << std::endl;
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound(); //will output the cat sound!
    wj->makeSound();
    wmeta->makeSound();

    delete wmeta;
    delete wj;
    delete wi;

    return (0);
}