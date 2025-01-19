#include "Zombie.h"
#include <string>

Zombie*	newZombie(std::string name)
{
	Zombie* zombie;

	try
	{
		zombie = new Zombie(name);
	}
	catch (const std::bad_alloc& e)
	{
		zombie = NULL;
	}
	return (zombie);
}