#ifndef POINT_H_
#define POINT_H_

#include "Fixed.h"

class Point
{
public:
	Point();
	Point(const Fixed& xx, const Fixed& yy);
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
private:
	const Fixed x;
	const Fixed y;
};

#endif //POINT_H_