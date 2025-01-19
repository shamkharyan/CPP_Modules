#include "Harl.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl harl;

		harl.complain(argv[1]);
	}
	else
		std::cout << "Wrong argument count." << std::endl;

	return (0);
}