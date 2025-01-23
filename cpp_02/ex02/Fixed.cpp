#include "Fixed.h"
#include <iostream>
#include <cmath>

const int Fixed::fracBits = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input) : value(input << fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float input) : value(roundf(input * (1 << fracBits)))
{
	std::cout << "Float constuctor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : value(fixed.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	value = fixed.value;
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int Fixed::toInt() const
{
	return value >> fracBits;
}

float Fixed::toFloat() const
{
	return static_cast<float>(value) / static_cast<float>(1 << fracBits);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return value == fixed.value;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return value != fixed.value;
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return value > fixed.value;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return value >= fixed.value;
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return value < fixed.value;
}
	
bool Fixed::operator<=(const Fixed& fixed) const
{
	return value <= fixed.value;
}

Fixed& Fixed::operator+(const Fixed& fixed)
{
	value += fixed.value;
	return *this;
}

Fixed& Fixed::operator-(const Fixed& fixed)
{
	value -= fixed.value;
	return *this;
}

Fixed& Fixed::operator*(const Fixed& fixed)
{
	Fixed temp(toFloat() * fixed.toFloat());
	value = temp.value;
	return *this;
}

Fixed& Fixed::operator/(const Fixed& fixed)
{
	Fixed temp(toFloat() / fixed.toFloat());
	value = temp.value;
	return *this;
}

Fixed& Fixed::operator++()
{
	++value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++value;
	return temp;
}

Fixed& Fixed::operator--()
{
	--value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--value;
	return temp;
}

 Fixed& Fixed::min(Fixed& a, Fixed& b)
 {
	return (a < b)? a : b;
 }

 const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
 {
	return (a < b)? a : b;
 }

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b)? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b)? a : b;
}
