#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "ScavTrap.h"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Untitled_clap_name")
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	mName = "Untitled";
	mMaxHealth = FragTrap::mMaxHealth;
	mHealth = FragTrap::mHealth;
	mEnergy = ScavTrap::mEnergy;
	mDamage = FragTrap::mDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap string constructor" << std::endl;
	mName = name;
	mMaxHealth = FragTrap::mMaxHealth;
	mHealth = FragTrap::mHealth;
	mEnergy = ScavTrap::mEnergy;
	mDamage = FragTrap::mDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap copy assign operator" << std::endl;
	if (this == &obj)
		return (*this);
	ClapTrap::operator=(obj);
	mName = obj.mName;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << mName << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::mName << std::endl;
}