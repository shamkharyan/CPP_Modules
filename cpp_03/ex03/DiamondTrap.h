#ifndef DIAMOND_TRAP_H_
#define DIAMOND_TRAP_H_

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& obj);
	void whoAmI();
private:
	std::string mName;
};

#endif //DIAMOND_TRAP_H_