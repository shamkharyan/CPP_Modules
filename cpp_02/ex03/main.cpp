#include "Point.h"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
	Point a;
	Point b(4.f, 0);
	Point c(2.f, 3.f);
	Point p(2.f, 1.f);

	if (bsp(a, b, c, p))
		std::cout << "** Point is inside the triangle **" << std::endl;
	else
		std::cout << "** Point is not inside the triangle **" << std::endl;
	return 0;
}