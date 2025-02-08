#ifndef FRAG_TRAP_H_
#define FRAG_TRAP_H_

#include "ClapTrap.h"
#include <string>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& obj);
	~FragTrap();
	FragTrap& operator=(const FragTrap& obj);
	void highFivesGuys();
};

#endif //FRAG_TRAP_H_
