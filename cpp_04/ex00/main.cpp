#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "WrongDog.h"
#include <iostream>

int main()
{
	std::cout << "** Testing Animal default constructor **" << std::endl;
    const Animal* a1 = new Animal();
	std::cout << a1->getType() << '\n' << std::endl;

	std::cout << "** Testing Animal string constructor **" << std::endl;
	const Animal* a2 = new Animal("Some");
	std::cout << a2->getType() << '\n' << std::endl;

	std::cout << "** Testing Animal copy constructor **" << std::endl;
	Animal* a3 = new Animal(*a1);
	std::cout << a3->getType() << '\n' << std::endl;

	std::cout << "** Testing Animal copy assignment operator **" << std::endl;
	*a3 = *a2;
	*a3 = *a3;
	std::cout << a3->getType() << '\n' << std::endl;

	std::cout << "** Testing Animal makeSound method **" << std::endl;
	a3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing Animal destructor **" << std::endl;
	delete a1;
	delete a2;
	delete a3;
	std::cout << std::endl;

	std::cout << "** Testing Cat default constructor **" << std::endl;
    const Cat* c1 = new Cat();
	std::cout << c1->getType() << '\n' << std::endl;

	std::cout << "** Testing Cat copy constructor **" << std::endl;
	const Cat* c2 = new Cat();
	Cat* c3 = new Cat(*c1);
	std::cout << c3->getType() << '\n' << std::endl;

	std::cout << "** Testing Cat copy assignment operator **" << std::endl;
	*c3 = *c2;
	*c3 = *c3;
	std::cout << c3->getType() << '\n' << std::endl;

	std::cout << "** Testing Cat makeSound method **" << std::endl;
	c3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing Cat destructor **" << std::endl;
	delete c1;
	delete c2;
	delete c3;
	std::cout << std::endl;

	std::cout << "** Testing dynamic polymorphism for Cat **" << std::endl;
    const Animal* i = new Cat();
    std::cout << i->getType() << std::endl;
    i->makeSound(); //will output the cat sound!
	delete i;
	std::cout << std::endl;

	std::cout << "** Testing Dog default constructor **" << std::endl;
    const Dog* d1 = new Dog();
	std::cout << d1->getType() << '\n' << std::endl;

	std::cout << "** Testing Dog copy constructor **" << std::endl;
	const Dog* d2 = new Dog();
	Dog* d3 = new Dog(*d1);
	std::cout << d3->getType() << '\n' << std::endl;

	std::cout << "** Testing Dpg copy assignment operator **" << std::endl;
	*d3 = *d2;
	*d3 = *d3;
	std::cout << d3->getType() << '\n' << std::endl;

	std::cout << "** Testing Dog makeSound method **" << std::endl;
	d3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing Dog destructor **" << std::endl;
	delete d1;
	delete d2;
	delete d3;
	std::cout << std::endl;

	std::cout << "** Testing dynamic polymorphism for Dog **" << std::endl;
    const Animal* j = new Dog();
    std::cout << j->getType() << std::endl;
    j->makeSound(); //will output the dog sound!
	delete j;
	std::cout << std::endl;

	//Wrong Ones
	std::cout << "** Testing WrongAnimal default constructor **" << std::endl;
    const WrongAnimal* wa1 = new WrongAnimal();
	std::cout << wa1->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongAnimal string constructor **" << std::endl;
	const WrongAnimal* wa2 = new WrongAnimal("Some");
	std::cout << wa2->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongAnimal copy constructor **" << std::endl;
	WrongAnimal* wa3 = new WrongAnimal(*wa1);
	std::cout << wa3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongAnimal copy assignment operator **" << std::endl;
	*wa3 = *wa2;
	*wa3 = *wa3;
	std::cout << wa3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongAnimal makeSound method **" << std::endl;
	wa3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing WrongAnimal destructor **" << std::endl;
	delete wa1;
	delete wa2;
	delete wa3;
	std::cout << std::endl;

	std::cout << "** Testing WrongCat default constructor **" << std::endl;
    const WrongCat* wc1 = new WrongCat();
	std::cout << wc1->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongCat copy constructor **" << std::endl;
	const WrongCat* wc2 = new WrongCat();
	WrongCat* wc3 = new WrongCat(*wc1);
	std::cout << wc3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongCat copy assignment operator **" << std::endl;
	*wc3 = *wc2;
	*wc3 = *wc3;
	std::cout << wc3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongCat makeSound method **" << std::endl;
	wc3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing WrongCat destructor **" << std::endl;
	delete wc1;
	delete wc2;
	delete wc3;
	std::cout << std::endl;

	std::cout << "** Testing dynamic polymorphism for WrongCat **" << std::endl;
    const WrongAnimal* wi = new WrongCat();
    std::cout << wi->getType() << std::endl;
    wi->makeSound(); //will output the animal sound!
	delete wi;
	std::cout << std::endl;

	std::cout << "** Testing WrongDog default constructor **" << std::endl;
    const WrongDog* wd1 = new WrongDog();
	std::cout << wd1->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongDog copy constructor **" << std::endl;
	const WrongDog* wd2 = new WrongDog();
	WrongDog* wd3 = new WrongDog(*wd1);
	std::cout << wd3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongDog copy assignment operator **" << std::endl;
	*wd3 = *wd2;
	*wd3 = *wd3;
	std::cout << d3->getType() << '\n' << std::endl;

	std::cout << "** Testing WrongDog makeSound method **" << std::endl;
	wd3->makeSound();
	std::cout << std::endl;

	std::cout << "** Testing WrongDog destructor **" << std::endl;
	delete wd1;
	delete wd2;
	delete wd3;
	std::cout << std::endl;

	std::cout << "** Testing dynamic polymorphism for WrongDog **" << std::endl;
    const WrongAnimal* wj = new WrongDog();
    std::cout << wj->getType() << std::endl;
    wj->makeSound(); //will output the animal sound!
	delete wj;
	std::cout << std::endl;

    return (0);
}
