#include "AMateria.h"
#include "Cure.h"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	AMateria::operator=(other);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}