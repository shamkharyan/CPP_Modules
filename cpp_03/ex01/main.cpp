#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
	ScavTrap obj1;
	ScavTrap obj2("Bob");
	ScavTrap obj3 = obj1;
	obj3 = obj2;

	obj3.attack("James");
	obj3.takeDamage(10);
	obj3.beRepaired(7);
	obj3.guardGate();

	return 0;
}