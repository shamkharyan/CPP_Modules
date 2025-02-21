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
	{
		std::cout << "** Cure default constructor test **" << std::endl;
		Cure *c = new Cure();
		c->getType();
		delete c;
	}
	std::cout << std::endl;

	{	
		std::cout << "** Cure copy constructor test **" << std::endl;
		Cure *c1 = new Cure();
		Cure *c2 = new Cure(*c1);
		c1->getType();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Cure copy assignment operator test **" << std::endl;
		Cure *c1 = new Cure();
		Cure *c2 = new Cure();
		*c2 = *c1;
		*c2 = *c2;
		c1->getType();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Cure clone method test **" << std::endl;
		Cure *c1 = new Cure();
		AMateria *c2 = c1->clone();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Cure use method test **" << std::endl;
		ICharacter *ch = new Character("Test");
		Cure *c = new Cure();
		c->use(*ch);
		delete c;
		delete ch;
	}
	std::cout << std::endl;

	{
		std::cout << "** Ice default constructor test **" << std::endl;
		Ice *c = new Ice();
		c->getType();
		delete c;
	}
	std::cout << std::endl;

	{	
		std::cout << "** Ice copy constructor test **" << std::endl;
		Ice *c1 = new Ice();
		Ice *c2 = new Ice(*c1);
		c1->getType();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Ice copy assignment operator test **" << std::endl;
		Ice *c1 = new Ice();
		Ice *c2 = new Ice();
		*c2 = *c1;
		*c2 = *c2;
		c1->getType();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Ice clone method test **" << std::endl;
		Ice *c1 = new Ice();
		AMateria *c2 = c1->clone();
		c2->getType();
		delete c1;
		delete c2;
	}
	std::cout << std::endl;

	{
		std::cout << "** Ice use method test **" << std::endl;
		ICharacter *ch = new Character("Test");
		Ice *c = new Ice();
		c->use(*ch);
		delete c;
		delete ch;
	}
	std::cout << std::endl;

	{
		std::cout << "** MateriaSource default constructor test **" << std::endl;
		IMateriaSource *m = new MateriaSource();
		delete m;
	}
	std::cout << std::endl;

	{
		std::cout << "** MateriaSource copy constructor test **" << std::endl;
		MateriaSource *m = new MateriaSource();
		m->learnMateria(new Ice());
		m->learnMateria(new Cure());
		MateriaSource *m2 = new MateriaSource(*m);
		AMateria *a = m2->createMateria("ice");
		AMateria *b = m2->createMateria("cure");
		delete m;
		delete m2;
		delete a;
		delete b;
	}
	std::cout << std::endl;

	{
		std::cout << "** MateriaSource copy assignment operator test **" << std::endl;
		MateriaSource *m = new MateriaSource();
		m->learnMateria(new Ice());
		m->learnMateria(new Cure());

		MateriaSource *m2 = new MateriaSource();
		m2->learnMateria(new Ice());
		*m2 = *m;
		*m2 = *m2;
		AMateria *a = m2->createMateria("ice");
		AMateria *b = m2->createMateria("cure");
		delete m;
		delete m2;
		delete a;
		delete b;
	}
	std::cout << std::endl;

	{
		std::cout << "** MateriaSource learnMateria method test **" << std::endl;
		IMateriaSource *m = new MateriaSource();
		m->learnMateria(NULL);
		m->learnMateria(new Ice());
		m->learnMateria(NULL);
		m->learnMateria(new Cure());
		m->learnMateria(new Ice());
		m->learnMateria(new Cure());
		m->learnMateria(NULL);
		AMateria *test = new Cure();
		m->learnMateria(test);
		delete m;
		delete test;
	}
	std::cout << std::endl;

	{
		std::cout << "** MateriaSource createMateria method test **" << std::endl;
		IMateriaSource *m = new MateriaSource();
		m->learnMateria(new Ice());
		m->learnMateria(new Cure());
		AMateria *a1 = m->createMateria("ice");
		AMateria *a2 = m->createMateria("cure");
		AMateria *a3 = m->createMateria("other");
		delete a1;
		delete a2;
		delete a3;
		delete m;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character default constructor test **" << std::endl;
		ICharacter *c = new Character();
		std::cout << c->getName() << std::endl;
		delete c;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character string constructor test **" << std::endl;
		ICharacter *c = new Character("Test");
		std::cout << c->getName() << std::endl;
		delete c;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character copy constructor test **" << std::endl;
		Character *c = new Character("Test");
		c->equip(new Ice());
		c->equip(new Cure());
		Character *c1 = new Character(*c);
		std::cout << c1->getName() << std::endl;
		c1->use(0, *c);
		c1->use(1, *c);
		delete c;
		delete c1;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character copy assignment operator test **" << std::endl;
		Character *c = new Character("Test");
		c->equip(new Ice());
		c->equip(new Cure());
		Character *c1 = new Character();
		std::cout << c1->getName() << std::endl;
		c1->equip(new Ice());
		*c1 = *c;
		*c1 = *c1;
		std::cout << c1->getName() << std::endl;
		c1->use(0, *c);
		c1->use(1, *c);
		delete c;
		delete c1;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character equip method test **" << std::endl;
		ICharacter *c = new Character("Test");
		AMateria *a[5];

		for (int i = 0; i < 5; ++i)
		{
			if (i % 2)
				a[i] = new Ice();
			else
				a[i] = new Cure();
		}

		for (int i = 0; i < 5; ++i)
		{
			c->equip(a[i]);
			c->use(i, *c);
		}

		c->unequip(1);
		c->equip(a[4]);
		c->use(1, *c);
		c->unequip(0);
		c->unequip(1);
		c->equip(a[0]);

		for (int i = 0; i < 5; ++i)
		{
			c->unequip(i);
			delete a[i];
		}
		delete c;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character unequip method test **" << std::endl;
		ICharacter *c = new Character();

		c->unequip(0);
		c->unequip(-1);
		c->unequip(10);
		AMateria *a1 = new Ice();
		AMateria *a2 = new Ice();
		c->equip(a1);
		c->equip(a2);
		c->unequip(3);
		c->use(0, *c);
		c->unequip(0);
		c->use(0, *c);
		c->use(1, *c);
		c->unequip(1);
		c->use(1, *c);
		c->unequip(0);
		delete a1;
		delete a2;
		delete c;
	}
	std::cout << std::endl;

	{
		std::cout << "** Character use method test **" << std::endl;
		ICharacter *c = new Character();

		c->use(0, *c);
		AMateria *a1 = new Ice();
		AMateria *a2 = new Ice();
		c->equip(a1);
		c->equip(a2);
		c->use(0, *c);
		c->use(1, *c);
		c->use(-1, *c);
		c->unequip(0);
		c->use(0, *c);
		c->unequip(1);
		delete a1;
		delete a2;
		delete c;
	}
	std::cout << std::endl;

	return 0;
}