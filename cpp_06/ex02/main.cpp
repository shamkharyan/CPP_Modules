#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(std::time(NULL));
	Base *ptr[5];

	for (int i = 0; i < 5; ++i)
		ptr[i] = generate();

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "By Pointer: ";
		identify(ptr[i]);
		std::cout << "By Reference: ";
		identify(*ptr[i]);
	}

	for (int i = 0; i < 5; ++i)
		delete ptr[i];

}