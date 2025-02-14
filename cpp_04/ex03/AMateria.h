#ifndef A_MATERIA_H_
#define A_MATERIA_H_

#include <string>
#include "ICharacter.h"

class ICharacter;

class AMateria
{
protected:
	std::string mType;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& other);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //A_MATERIA_H_