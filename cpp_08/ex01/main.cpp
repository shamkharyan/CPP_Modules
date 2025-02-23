#include "Span.hpp"
#include <iostream>

int main()
{
	Span s;
	s.fill();
	std::cout << s.longestSpan() << std::endl;
	std::cout << s.shortestSpan() << std::endl;
	return (0);
}
