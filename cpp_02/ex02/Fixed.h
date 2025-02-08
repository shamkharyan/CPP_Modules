#ifndef FIXED_H_
#define FIXED_H_

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	int		getRawBits() const;
	void	setRawBits(const int raw);
	int		toInt() const;
	float	toFloat() const;

	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;
	bool operator>(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;

	const Fixed operator+(const Fixed& fixed) const;
	const Fixed operator-(const Fixed& fixed) const;
	const Fixed operator*(const Fixed& fixed) const;
	const Fixed operator/(const Fixed& fixed) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
private:
	int					value;
	static const int	fracBits;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif //FIXED_H_
