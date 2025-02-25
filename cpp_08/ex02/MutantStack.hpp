#ifndef MUTANT_STACK_HPP_
#define MUTANT_STACK_HPP_

#include <stack>
#include <list>

template <typename T>
class MutantStack : public : std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator Iterator;
    typedef typename std::stack<T>::container_type::const_iterator CIterator;
    typedef typename std::stack<T>::container_type::reverse_iterator RIterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator CRIterator;

    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);

    Iterator begin();
    Iterator end();

    CIterator begin() const;
    CIterator end() const;

    RIterator rbegin();
    RIterator rend();

    CRIterator rbegin() const;
    CRIterator rend() const;
};

#include "MutantStack.ipp"

#endif //MUTANT_STACK_HPP_