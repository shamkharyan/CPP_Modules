#include "Harl.h"
#include <iostream>
#include <string>

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<< "I really do!"
				<< std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn’t put enough bacon in my burger!\n"
			  << "If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month."
				<< std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funcPTRS[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int i;

	for (i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			break;
	}

	switch (i)
	{
		case (0):
		(this->*funcPTRS[0])();
		__attribute__((fallthrough)); //For Linux to compile
		case (1):
		(this->*funcPTRS[1])();
		__attribute__((fallthrough));
		case (2):
		(this->*funcPTRS[2])();
		__attribute__((fallthrough)); 
		case (3):
		(this->*funcPTRS[3])();
		break;
		default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}