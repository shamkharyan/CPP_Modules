#include "ClapTrap.h"

int main()
{
	ClapTrap obj1;
	ClapTrap obj2("Bob");
	ClapTrap obj3 = obj1;
	obj3 = obj2;

	obj3.attack("Ashley");
	obj3.takeDamage(5);
	obj3.beRepaired(3);
	obj3.takeDamage(100);
	obj3.attack("Rob");
	obj3.beRepaired(1);

	return 0;
}
