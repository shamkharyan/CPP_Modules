#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(const std::string& type);
	~Weapon();
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	void setType(const std::string& type);
	const std::string& getType() const;
private:
	std::string	mType;
};

#endif //WEAPON_H_
