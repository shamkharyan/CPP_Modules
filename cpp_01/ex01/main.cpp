#include "Zombie.h"
#include <string>
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int n;

	std::cout << "Enter zombie count: ";
	std::cin >> n;

	Zombie* zombies = zombieHorde(n, "Foo");
	if (!zombies)
		std::cout << "Bad allocation for zombieHorde" << std::endl;
	else
		zombies[0].announce();
	delete [] zombies;
}