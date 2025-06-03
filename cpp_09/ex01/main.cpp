#include "RPN.hpp"
#include <iostream>
#include <climits>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cerr << "Expression is missing\n";
	else if (argc != 2)
		std::cerr << "To many expressions\n";
	else
	{
		try
		{
			RPN value(argv[1]);
			std::cout << value.evaluate() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}