#include "Brain.h"
#include <iostream>

Brain::Brain() : mSize(0)
{
    std::cout << "Brain default constructor" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain copy constructor" << std::endl;
    for (unsigned i = 0; i < brain.mSize; ++i)
        mIdeas[i] = brain.mIdeas[i];
    mSize = brain.mSize;
}

Brain& Brain::operator=(const Brain& brain)
{
    std::cout << "Brain copy assignment operator" << std::endl;
    if (this == &brain)
        return (*this);
    for (unsigned i = 0; i < brain.mSize; ++i)
        mIdeas[i] = brain.mIdeas[i];
    mSize = brain.mSize;
    return (*this);
}

void Brain::addIdea(const std::string& idea)
{
    if (mSize == 100)
        return;
    mIdeas[mSize++] = idea;
}

const std::string& Brain::getIdea(unsigned i) const
{
    if (i < mSize)
        return mIdeas[i];
    else
        throw std::out_of_range("Wrong index");
}

unsigned Brain::getSize() const
{
    return mSize;
}
