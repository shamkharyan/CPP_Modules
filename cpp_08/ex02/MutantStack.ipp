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
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    return c.begin();
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    return c.end();
}

template <typename T>
typename MutantStack<T>::CIterator MutantStack<T>::begin() const
{
    return c.begin();
}

template <typename T>
typename MutantStack<T>::CIterator MutantStack<T>::end() const
{
    return c.end();
}

template <typename T>
typename MutantStack<T>::RIterator MutantStack<T>::rbegin()
{
    return c.rbegin();
}

template <typename T>
typename MutantStack<T>::RIterator MutantStack<T>::rend()
{
    return c.rend();
}

template <typename T>
typename MutantStack<T>::CRIterator MutantStack<T>::rbegin() const
{
    return c.rbegin();
}

template <typename T>
typename MutantStack<T>::CRIterator MutantStack<T>::rend() const
{
    return c.rend();
}




