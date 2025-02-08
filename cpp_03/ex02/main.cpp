#include "ClapTrap.h"
#include "FragTrap.h"

int main()
{
	FragTrap obj1;
	FragTrap obj2("Bob");
	FragTrap obj3 = obj1;
	obj3 = obj2;

	obj3.attack("James");
	obj3.takeDamage(10);
	obj3.beRepaired(5);
	obj3.highFivesGuys();

	return 0;
}
