#include "Weapon.h"
#include "HumanB.h"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name) : mName(name), mWeapon(NULL) {}

HumanB::~HumanB() {}

HumanB::HumanB(const HumanB& humanB) : mName(humanB.mName), mWeapon(humanB.mWeapon) {}

HumanB& HumanB::operator=(const HumanB& humanB)
{
	if (this == &humanB)
		return *this;
	mName = humanB.mName;
	mWeapon = humanB.mWeapon;
	return *this;
}

void HumanB::setWeapon(Weapon& weapon)
{
	mWeapon = &weapon;
}

void HumanB::attack() const
{
	if (mWeapon)
		std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
	else
		std::cout << mName << " don't have any weapon" << std::endl;
}