#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "MutantStack default constructor" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
    std::cout << "MutantStack copy constructor" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    std::cout << "MutantStack copy assignment operator" << std::endl;
    if (this == &other)
        return (*this);
    std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return std::stack<T>::c.rend();
}




