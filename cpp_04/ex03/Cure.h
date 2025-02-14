#ifndef CURE_H_
#define CURE_H_

#include "ICharacter.h"
#include "AMateria.h"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif //CURE_H_