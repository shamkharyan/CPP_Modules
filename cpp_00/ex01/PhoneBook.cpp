#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : mSize(0), mCurrent(0) {}
PhoneBook::~PhoneBook() {}

std::string	PhoneBook::crop(const std::string& value) const
{
	if (value.size() > 10)
		return value.substr(0, 9) + ".";
	return value;
}

void	PhoneBook::add()
{
	std::string	input;
	Contact		temp;

	std::cout << "Enter first name: ";
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
			return;
		if (temp.setFirstName(input))
			break;
		std::cout << "First name can contain letters only." << std::endl;
		std::cout << "Re-enter first name: ";
	}

	std::cout << "Enter last name: ";
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
			return;
		if (temp.setLastName(input))
			break;
		std::cout << "Last name can contain letters only." << std::endl;
		std::cout << "Re-enter last name: ";
	}

	std::cout << "Enter nickname: ";
	std::cin >> input;
	if (std::cin.fail())
			return;
	temp.setNickname(input);

	std::cout << "Enter phone number: ";
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
			return;
		if (temp.setPhoneNumber(input))
			break;
		std::cout << "Phone number can contain digits only." << std::endl;
		std::cout << "Re-enter phone number: ";
	}

	std::cout << "Enter darkest secret: ";
	std::cin >> input;
	if (std::cin.fail())
			return;
	temp.setSecret(input);

	mContacts[mCurrent] = temp;
	mCurrent = (mCurrent + 1) % BUFFER_SIZE;
	if (mSize < BUFFER_SIZE)
		++mSize;
}

void	PhoneBook::search() const
{
	if (mSize == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << '|' << std::setw(10) << std::right << "Index"
			  << '|' << std::setw(10) << std::right << "First Name"
          	  << '|' << std::setw(10) << std::right << "Last Name"
              << '|' << std::setw(10) << std::right << "Phone"
              << '|' << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << '-' << std::setfill(' ') << std::endl;
	for (std::size_t i = 0; i < mSize; ++i)
	{
		std::cout << '|' << std::setw(10) << std::right << (i + 1)
				  << '|' << std::setw(10) << std::right << crop(mContacts[i].getFirstName())
          	      << '|' << std::setw(10) << std::right << crop(mContacts[i].getLastName())
                  << '|' << std::setw(10) << std::right << crop(mContacts[i].getPhoneNumber())
                  << '|' << std::endl;
	}

	std::string index;

	std::cout << std::endl;
	std::cout << "Enter index : ";
	while (true)
	{
		std::cin >> index;
		if (std::cin.fail())
			return;
		if (index.size() == 1 && index[0] >= '1' && index[0] <= static_cast<int>(mSize) + '0')
			break;
		std::cout << "Invalid index: Must be number from 1 to " << mSize << std::endl;
		std::cout << "Re-enter index: ";
	}
	std::cout << "  First Name : " << mContacts[index[0] - '0' - 1].getFirstName() << std::endl;
	std::cout << "   Last Name : " << mContacts[index[0] - '0' - 1].getLastName() << std::endl;
	std::cout << "    Nickname : " << mContacts[index[0] - '0' - 1].getNickname() << std::endl;
	std::cout << "Phone number : " << mContacts[index[0] - '0' - 1].getPhoneNumber() << std::endl;
	std::cout << std::endl;
}
