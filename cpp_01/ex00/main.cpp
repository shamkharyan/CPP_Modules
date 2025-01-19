#include "Zombie.h"
#include <string>
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *zombie = newZombie("Foo");
	if (zombie)
		zombie->announce();
	else
		std::cout << "Bad allocation for Foo" << std::endl;
	randomChump("Bar");
	delete zombie;
	return (0);
}