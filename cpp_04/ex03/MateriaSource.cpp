#include "MateriaSource.h"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		mMateria[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete mMateria[i];
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.mMateria[i])
			mMateria[i] = other.mMateria[i]->clone();
		else
			mMateria[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment operator" << std::endl;
	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; ++i)
		delete mMateria[i];

	for (int i = 0; i < 4; ++i)
	{
		if (other.mMateria[i])
			mMateria[i] = other.mMateria[i]->clone();
		else
			mMateria[i] = NULL;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		std::cout << "Cant learn NULL." << std::endl;
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!mMateria[i])
			{
				mMateria[i] = materia;
				return;
			}
		}
		std::cout << "Cant learn materia anymore." << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (mMateria[i] && mMateria[i]->getType() == type)
			return mMateria[i]->clone();
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}
