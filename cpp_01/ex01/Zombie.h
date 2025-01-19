#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	Zombie(const Zombie& zombie);
	Zombie& operator=(const Zombie& zombie);
	void announce() const;
	void setName(const std::string& name);
	std::string getName() const;
private:
	std::string	mName;
};

#endif //ZOMBIE_H_