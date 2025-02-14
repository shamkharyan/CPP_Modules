#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ICharacter.h"
#include "AMateria.h"
#include <string>

class Character : public ICharacter
{
private:
	std::string mName;
	AMateria* mInventory[4];
public:
	Character();
	Character(const std::string& name);
	~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
	std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif //CHARACTER_H_