#ifndef ICE_H_
#define ICE_H_

#include "ICharacter.h"
#include "AMateria.h"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif //ICE_H_