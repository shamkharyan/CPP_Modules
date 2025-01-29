#include "Point.h"
#include "Fixed.h"

static Fixed signedArea(const Point a, const Point b, const Point c)
{
	return Fixed(
		(a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY())
	);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed a1, a2, a3;

	a1 = signedArea(point, a, b);
	a2 = signedArea(point, b, c);
	a3 = signedArea(point, c, a);

	return (a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0);
}