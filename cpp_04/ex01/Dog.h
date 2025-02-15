#ifndef DOG_H_
#define DOG_H_

#include "Brain.h"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    void makeSound() const;
    Brain* getBrain() const;
private:
    Brain *mBrain;
};

#endif //DOG_H_
