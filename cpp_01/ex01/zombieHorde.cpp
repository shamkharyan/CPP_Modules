#include "Zombie.h"
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombies;

	try
	{
		zombies = new Zombie[N];
		for (int i = 0; i < N; ++i)
			zombies[i].setName(name);
	}
	catch (const std::bad_alloc& e)
	{
		zombies = NULL;
	}
	return (zombies);
}