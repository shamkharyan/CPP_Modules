#include "ICharacter.h"
#include "Character.h"
#include <string>
#include <iostream>

Character::Character() : mName("Default")
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		mInventory[i] = NULL;
}

Character::Character(const std::string& name) : mName(name)
{
	std::cout << "Character string constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		mInventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete mInventory[i];
}

Character::Character(const Character& other) : mName(other.mName)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.mInventory[i])
			mInventory[i] = other.mInventory[i]->clone();
		else
			mInventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; ++i)
		delete mInventory[i];
	for (int i = 0; i < 4; ++i)
	{
		if (other.mInventory[i])
			mInventory[i] = other.mInventory[i]->clone();
		else
			mInventory[i] = NULL;
	}
	return (*this);
}

std::string const & Character::getName() const { return mName; }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!mInventory[i])
		{
			std::cout << "Equiped at index " << i << std::endl;
			mInventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (mInventory[idx])
			mInventory[idx] = NULL;
		else
			std::cout << "Empty slot." << std::endl;
	}
	else
		std::cout << "Wrong index." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (mInventory[idx])
			mInventory[idx]->use(target);
		else
			std::cout << "Empty slot." << std::endl;
	}
	else
		std::cout << "Wrong index." << std::endl;
}

