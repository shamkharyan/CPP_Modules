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

private:
	int					value;
	static const int	fracBits;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif //FIXED_H_