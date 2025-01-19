#ifndef HUMAN_B_H_
#define HUMAN_B_H_

#include "Weapon.h"
#include <string>

class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();
	HumanB(const HumanB& humanB);
	HumanB& operator=(const HumanB& humanB);
	void setWeapon(Weapon& weapon);
	void attack() const;
private:
	std::string mName;
	Weapon* mWeapon;
};

#endif //HUMAN_B_H_