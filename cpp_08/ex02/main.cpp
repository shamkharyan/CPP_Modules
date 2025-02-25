#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    for (int i = 0; i < 5; ++i)
        mstack.push_front(i);
}