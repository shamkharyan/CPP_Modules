#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include "Brain.h"

class Animal
{
public:
    Animal();
    Animal(const std::string& type);
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const;
    std::string getType() const;
protected:
    std::string mType;
};

#endif //ANIMAL_H_
