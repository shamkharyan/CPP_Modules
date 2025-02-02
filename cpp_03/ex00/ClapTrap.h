#ifndef CLAP_TRAP_H_
#define CLAP_TRAP_H_

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string mName;
	unsigned	mMaxHealth;
	unsigned	mHealth;
	unsigned	mEnergy;
	unsigned	mDamage;
};

#endif //CLAP_TRAP_H_