#ifndef MUTANT_STACK_HPP_
#define MUTANT_STACK_HPP_

#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();

    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.ipp"

#endif //MUTANT_STACK_HPP_