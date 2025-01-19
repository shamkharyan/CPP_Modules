#include "Weapon.h"
#include "HumanA.h"
#include <string>
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : mName(name), mWeapon(weapon) {}

HumanA::~HumanA() {}

HumanA::HumanA(const HumanA& humanA) : mName(humanA.mName), mWeapon(humanA.mWeapon) {}

HumanA& HumanA::operator=(const HumanA& humanA)
{
	if (this == &humanA)
		return *this;
	mName = humanA.mName;
	mWeapon = humanA.mWeapon;
	return *this;
}

void HumanA::attack() const
{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}