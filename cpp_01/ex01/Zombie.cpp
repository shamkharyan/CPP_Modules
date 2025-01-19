#include "Zombie.h"
#include <string>
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : mName(name) {}

Zombie::Zombie(const Zombie& zombie) : mName(zombie.mName) {}

Zombie::~Zombie()
{
	std::cout << mName << ": Destructor" << std::endl;
}

Zombie& Zombie::operator=(const Zombie& zombie)
{
	if (this == &zombie)
		return *this;
	mName = zombie.mName;
	return *this;
}

void Zombie::announce() const
{
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	mName = name;
}

std::string	Zombie::getName() const
{
	return mName;
}