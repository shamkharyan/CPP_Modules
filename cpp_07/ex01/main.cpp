#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void display(const T& val)
{
	std::cout << val << std::endl;
}

int main()
{
	int i[] = { -1, 0, 42, 1024 };
	char c[] = "abcd";
	float f[] = { 1.2, 3.4, 5.6, 7.8 };
	std::string s[] = { "This", "is", "iter", "function" };

	iter(i, 4, &display);
	iter(c, 4, &display);
	iter(f, 4, &display);
	iter(s, 4, &display);
	return 0;
}
