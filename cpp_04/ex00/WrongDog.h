#ifndef WRONG_DOG_H_
#define WRONG_DOG_H_

class WrongDog : public WrongAnimal
{
public:
    WrongDog();
    ~WrongDog();
    WrongDog(const WrongDog& wrongDog);
    WrongDog& operator=(const WrongDog& wrongDog);
    void makeSound() const;
};

#endif //WRONG_DOG_H_
