#ifndef WRONG_ANIMAL_H_
#define WRONG_ANIMAL_H_

#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const std::string& type);
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    void makeSound() const;
    std::string getType() const;
protected:
    std::string mType;
};

#endif //WRONG_ANIMAL_H_
