#include "FragTrap.h"
#include "ClapTrap.h"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	mMaxHealth = 100;
	mHealth = 100;
	mEnergy = 100;
	mDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor" << std::endl;
	mMaxHealth = 100;
	mHealth = 100;
	mEnergy = 100;
	mDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "FragTrap copy assign operator" << std::endl;
	if (this == &obj)
		return (*this);
	ClapTrap::operator=(obj);
	return (*this);
}

void FragTrap::highFivesGuys()
{
	if (mHealth)
		std::cout << "FragTrap " << mName << " requests high five!" << std::endl;
	else
		std::cout << "FragTrap " << mName << " is dead!" << std::endl;
}
