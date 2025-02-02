#include "ScavTrap.h"
#include "ClapTrap.h"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	mMaxHealth = 100;
	mHealth = 100;
	mEnergy = 50;
	mDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap string constructor" << std::endl;
	mMaxHealth = 100;
	mHealth = 100;
	mEnergy = 50;
	mDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy assign operator" << std::endl;
	if (this == &obj)
		return (*this);
	ClapTrap::operator=(obj);
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (mHealth && mEnergy)
	{
		std::cout << "ScavTrap " 
					<< mName 
					<< " attacks " 
					<< target 
					<< " causing "
					<< mDamage
					<< " points of damage!" 
					<< std::endl;
		--mEnergy;
	}
	else if (!mHealth)
		std::cout << "ScavTrap " << mName << " is dead!" << std::endl;
	else
		std::cout << "ScavTrap " << mName << " has no energy!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (mHealth)
		std::cout << "ScavTrap " << mName << " is in gate keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << mName << " is dead!" << std::endl;
}