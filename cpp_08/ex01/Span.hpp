#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>

class Span
{
private:
	std::vector<int> mStorage;
public:
	Span();
	Span(unsigned capacity);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	void addNumber(unsigned n);
	void fill();
	unsigned shortestSpan() const;
	unsigned longestSpan() const;
	unsigned getSize() const;
	unsigned getCapacity() const;

	class NoSpanException : public std::exception
	{
		const char *what() const throw();
	};

	class StorageOverflowException : public std::exception
	{
		const char *what() const throw();
	};
};

#endif //SPAN_HPP_
