#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type)
{
	mType = type;
}

Weapon::~Weapon() {}

Weapon::Weapon(const Weapon& weapon) : mType(weapon.mType) {}

Weapon& Weapon::operator=(const Weapon& weapon)
{
	if (this == &weapon)
		return *this;
	mType = weapon.mType;
	return *this;
}

void Weapon::setType(const std::string& type)
{
	mType = type;
}

const std::string& Weapon::getType() const
{
	return mType;
}