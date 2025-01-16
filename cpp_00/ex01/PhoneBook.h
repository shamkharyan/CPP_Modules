#ifndef PHONE_BOOK_H_
#define PHONE_BOOK_H_

#define BUFFER_SIZE 8

#include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search() const;
private:
	std::string	crop(const std::string& value) const;
private:
	Contact mContacts[BUFFER_SIZE];
	std::size_t		mSize;
	std::size_t		mCurrent;
};

#endif //PHONE_BOOK_H_
