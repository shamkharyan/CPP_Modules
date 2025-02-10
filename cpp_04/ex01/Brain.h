#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain
{
public:
    Brain();
    ~Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    void addIdea(const std::string& idea);
    const std::string& getIdea(unsigned i) const;
    unsigned getSize() const;
private:
    std::string mIdeas[100];
    unsigned mSize;
};

#endif //BRAIN_H_