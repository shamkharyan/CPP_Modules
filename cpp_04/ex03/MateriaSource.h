#ifndef MATERIA_SOURCE_H_
#define MATERIA_SOURCE_H_

#include "AMateria.h"
#include "IMateriaSource.h"
#include <string>

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
private:
	AMateria* mMateria[4];
};

#endif //MATERIA_SOURCE_H_
