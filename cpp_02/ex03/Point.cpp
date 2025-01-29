#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& xx, const Fixed& yy) : x(xx), y(yy) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point& point)
{
	(void) point;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }