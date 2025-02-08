#include "ClapTrap.h"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() : mName("Untitled"), mMaxHealth(10), mHealth(10), mEnergy(10), mDamage(0)
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : mName(name), mMaxHealth(10), mHealth(10), mEnergy(10), mDamage(0)
{
	std::cout << "ClapTrap string constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) :
mName(obj.mName), mMaxHealth(obj.mMaxHealth), mHealth(obj.mHealth), mEnergy(obj.mEnergy), mDamage(obj.mDamage)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy assign operator" << std::endl;
	if (this == &obj)
		return (*this);
	mName = obj.mName;
	mHealth = obj.mHealth;
	mMaxHealth = obj.mMaxHealth;
	mEnergy = obj.mEnergy;
	mDamage = obj.mDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (mHealth && mEnergy)
	{
		std::cout << "ClapTrap "
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
		std::cout << "ClapTrap " << mName << " is dead!" << std::endl;
	else
		std::cout << "ClapTrap " << mName << " has no energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap "
				<< mName
				<< " takes "
				<< amount
				<< " points of damage!"
				<< std::endl;
	if (mHealth > amount)
		mHealth -= amount;
	else
		mHealth = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (mHealth && mEnergy)
	{
		std::cout << "ClapTrap "
				<< mName
				<< " claims "
				<< amount
				<< " points of health!"
				<< std::endl;
		if (mHealth + amount < mMaxHealth)
			mHealth += amount;
		else
			mHealth = mMaxHealth;
		--mEnergy;
	}
	else if (!mHealth)
		std::cout << "ClapTrap " << mName << " is dead!" << std::endl;
	else
		std::cout << "ClapTrap " << mName << " has no energy!" << std::endl;
}
