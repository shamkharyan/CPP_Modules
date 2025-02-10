#ifndef DOG_H_
#define DOG_H_

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    void makeSound() const;
};

#endif //DOG_H_