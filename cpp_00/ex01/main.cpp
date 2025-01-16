#include <iostream>
#include "PhoneBook.h"

void	makeUpperCase(std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

int main()
{
	PhoneBook book;
	std::string input;

	while (true)
	{
		std::cout << "Enter Command: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Input is failed. Exiting..." << std::endl;
			break;
		}
		makeUpperCase(input);
		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command: Use ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
