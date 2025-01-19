#ifndef HUMAN_A_H_
#define HUMAN_A_H_

#include "Weapon.h"
#include <string>

class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	HumanA(const HumanA& humanA);
	HumanA& operator=(const HumanA& humanA);
	void attack() const;
private:
	std::string mName;
	Weapon& mWeapon;
};

#endif //HUMAN_A_H_