#ifndef RPN_HPP_
#define RPN_HPP_

#include <stack>
#include <string>

class RPN
{
private:
	std::string mExpression;
public:
	RPN();
	RPN(const std::string& expression);
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	const std::string& getExpression() const;
	int evaluate() const;
};

#endif //RPN_HPP_