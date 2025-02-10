#ifndef WRONG_CAT_H_
#define WRONG_CAT_H_

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& wrongCat);
    WrongCat& operator=(const WrongCat& wrongCat);
    void makeSound() const;
};

#endif //WRONG_CAT_H_