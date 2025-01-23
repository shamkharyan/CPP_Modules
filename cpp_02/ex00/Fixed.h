#ifndef FIXED_H_
#define FIXED_H_

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	int getRawBits() const;
	void setRawBits(const int raw);

private:
	int					value;
	static const int	fracBits;
};

#endif //FIXED_H_