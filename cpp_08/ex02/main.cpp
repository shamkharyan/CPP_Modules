#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "** MutantStack functionality test **" << std::endl;
        MutantStack<int> ms;

        ms.push(10);
        ms.push(20);
        ms.push(30);

        std::cout << ms.top() << std::endl;
        ms.pop();
        std::cout << ms.top() << std::endl;
        ms.pop();
        std::cout << ms.top() << std::endl;
        ms.push(42);
        std::cout << ms.top() << std::endl;

        MutantStack<int> mss = ms;
        std::cout << mss.top() << std::endl;
        mss.push(21);
        ms = mss;
        std::cout << ms.top() << std::endl;
    }
    std::cout << std::endl;

    {
        std::cout << "** MutantStack iterator test **" << std::endl;
        MutantStack<int> m1;

        m1.push(10);
        m1.push(20);
        m1.push(30);

        MutantStack<int>::iterator it1 = m1.begin();

        while (it1 != m1.end())
        {
            std::cout << *it1;
            ++it1;
        }

        MutantStack<std::string> m2;

        m2.push("Abc");
        m2.push("Def");
        m2.push("Xyz");

        MutantStack<std::string>::iterator it2 = m2.begin();

        while (it2 != m2.end())
        {
            std::cout << *it2;
            ++it2;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "** MutantStack const iterator test **" << std::endl;
        MutantStack<int> m1;

        m1.push(10);
        m1.push(20);
        m1.push(30);

        const MutantStack<int> m11 = m1;

        MutantStack<int>::const_iterator it1 = m11.begin();

        while (it1 != m11.end())
        {
            std::cout << *it1 << std::endl;
            ++it1;
        }

        MutantStack<std::string> m2;

        m2.push("Abc");
        m2.push("Def");
        m2.push("Xyz");

        const MutantStack<std::string> m22 = m2;

        MutantStack<std::string>::const_iterator it2 = m22.begin();

        while (it2 != m22.end())
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "** MutantStack reverse iterator test **" << std::endl;
        MutantStack<int> m1;

        m1.push(10);
        m1.push(20);
        m1.push(30);

        MutantStack<int>::reverse_iterator it1 = m1.rbegin();

        while (it1 != m1.rend())
        {
            std::cout << *it1 << std::endl;
            ++it1;
        }

        MutantStack<std::string> m2;

        m2.push("Abc");
        m2.push("Def");
        m2.push("Xyz");

        MutantStack<std::string>::reverse_iterator it2 = m2.rbegin();

        while (it2 != m2.rend())
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "** MutantStack const reverse iterator test **" << std::endl;
        MutantStack<int> m1;

        m1.push(10);
        m1.push(20);
        m1.push(30);

        const MutantStack<int> m11 = m1;

        MutantStack<int>::const_reverse_iterator it1 = m11.rbegin();

        while (it1 != m11.rend())
        {
            std::cout << *it1 << std::endl;
            ++it1;
        }

        MutantStack<std::string> m2;

        m2.push("Abc");
        m2.push("Def");
        m2.push("Xyz");

        const MutantStack<std::string> m22 = m2;

        MutantStack<std::string>::const_reverse_iterator it2 = m22.rbegin();

        while (it2 != m22.rend())
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }
    std::cout << std::endl;

    

    
}