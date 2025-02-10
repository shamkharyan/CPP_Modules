#ifndef CAT_H_
#define CAT_H_

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    void makeSound() const;
};

#endif //CAT_H_