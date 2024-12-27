#include "Contact.h"
#include <cctype>

Contact::Contact() {}
Contact::~Contact() {}

bool	Contact::setFirstName(const std::string& firstName)
{
	for (int i = 0; i < firstName.size(); ++i)
		if (!std::isalpha(firstName[i]))
			return false;
	mFirstName = firstName;
	mFirstName[0] = std::toupper(mFirstName[0]);
	return true;
}

bool	Contact::setLastName(const std::string& lastName)
{
	for (int i = 0; i < lastName.size(); ++i)
		if (!std::isalpha(lastName[i]))
			return false;
	mLastName = lastName;
	mLastName[0] = std::toupper(mLastName[0]);
	return true;
}

void	Contact::setNickname(const std::string& nickname) { mNickname = nickname; }

bool	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	for (int i = 0; i < phoneNumber.size(); ++i)
		if (!std::isdigit(phoneNumber[i]))
			return false;
	mPhoneNumber = phoneNumber;
	return true;
}

void	Contact::setSecret(const std::string& secret) { mSecret = secret; }

std::string Contact::getFirstName() const { return mFirstName; }
std::string Contact::getLastName() const { return mLastName; }
std::string Contact::getNickname() const { return mNickname; }
std::string Contact::getPhoneNumber() const { return mPhoneNumber; }
std::string Contact::getSecret() const { return mSecret; }