#ifndef SCAV_TRAP_H_
#define SCAV_TRAP_H_

#include "ClapTrap.h"
#include <string>

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj);
	void attack(const std::string& target);
	void guardGate();
};

#endif //SCAV_TRAP_H_