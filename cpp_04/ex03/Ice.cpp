#include "AMateria.h"
#include "Ice.h"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	AMateria::operator=(other);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}