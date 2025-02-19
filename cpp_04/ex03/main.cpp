#include "IMateriaSource.h"
#include "MateriaSource.h"
#include "Ice.h"
#include "Cure.h"
#include "AMateria.h"
#include "ICharacter.h"
#include "Character.h"
#include <iostream>

int main()
{
	std::cout << "** Cure default constructor test **" << std::endl;
	Cure *c1 = new Cure();
	std::cout << std::endl;

	std::cout << "** Cure copy constructor test **" << std::endl;
	Cure *c2 = new Cure(*c1);
	std::cout << std::endl;

	std::cout << "** Cure copy assignment operator test **" << std::endl;
	*c2 = *c1;
	*c2 = *c2;
	std::cout << std::endl;

	std::cout << "** Cure getType method test **" << std::endl;
	std::cout << c1->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "** Cure clone method test**" << std::endl;
	AMateria *c3 = c1->clone();
	std::cout << std::endl;

	std::cout << "** Cure Polymorphism test **" << std::endl;
	std::cout << c3->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "** Cure use method test **" << std::endl;
	Character *test1 = new Character();
	c2->use(*test1);
	delete test1;
	std::cout << std::endl;

	std::cout << "** Cure destructor test**" << std::endl;
	delete c1;
	delete c2;
	delete c3;
	std::cout << std::endl;

	std::cout << "** Ice default constructor test**" << std::endl;
	Ice *i1 = new Ice();
	std::cout << std::endl;

	std::cout << "** Ice copy constructor test**" << std::endl;
	Ice *i2 = new Ice(*i1);
	std::cout << std::endl;

	std::cout << "** Ice copy assignment operator test**" << std::endl;
	*i2 = *i1;
	*i2 = *i2;
	std::cout << std::endl;

	std::cout << "** Ice getType method test**" << std::endl;
	std::cout << i2->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "** Ice clone method test**" << std::endl;
	AMateria *i3 = i1->clone();
	std::cout << std::endl;

	std::cout << "** Ice Polymorphism test **" << std::endl;
	std::cout << i1->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "** Ice use method test **" << std::endl;
	Character *test2 = new Character();
	i2->use(*test2);
	delete test2;
	std::cout << std::endl;

	std::cout << "** Ice destructor test**" << std::endl;
	delete i1;
	delete i2;
	delete i3;
	std::cout << std::endl;

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}