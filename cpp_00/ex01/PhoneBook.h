#ifndef PHONE_BOOK_H_
#define PHONE_BOOK_H_

#include "Contact.h"

class PhoneBook
{
private:
	Contact mContacts[8];
	int		mSize;
public:
	void	add();
	void	search() const;
}

#endif //PHONE_BOOK_H_