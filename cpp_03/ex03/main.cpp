#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

int main()
{
	DiamondTrap obj1;
	DiamondTrap obj2("Bob");
	DiamondTrap obj3 = obj1;
	obj3 = obj2;

	obj3.attack("James");
	obj3.takeDamage(10);
	obj3.beRepaired(5);
	obj3.highFivesGuys();
	obj3.guardGate();
	obj3.whoAmI();

	return 0;
}
