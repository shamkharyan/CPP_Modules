#include "AMateria.h"
#include <string>
#include <iostream>

AMateria::AMateria(std::string const & type) : mType(type)
{
	std::cout << "AMateria string constructor" << std::endl;
}

AMateria::AMateria(const AMateria& other) : mType(other.mType)
{
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	mType = other.mType;
	return (*this);
}

std::string const & AMateria::getType() const { return mType; }

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
