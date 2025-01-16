#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>

class Contact
{
public:
	Contact();
	~Contact();
	bool	setFirstName(const std::string& firstName);
	bool	setLastName(const std::string& lastName);
	void	setNickname(const std::string& nickname);
	bool	setPhoneNumber(const std::string& phoneNumber);
	void	setSecret(const std::string& secret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;
private:
	std::string	mFirstName;
	std::string	mLastName;
	std::string	mNickname;
	std::string mPhoneNumber;
	std::string mSecret;
};

#endif //CONTACT_H_
