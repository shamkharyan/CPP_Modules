#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <climits>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const std::string& expression) : mExpression(expression) {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : mExpression(other.mExpression) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this == &other)
		return *this;
	mExpression = other.mExpression;
	return *this;
}

const std::string& RPN::getExpression() const
{
	return mExpression;
}

int RPN::evaluate() const
{
	std::stack<int> st;
	std::stringstream ss(mExpression);
	std::string token;

	while (ss >> token)
	{
		if (token.size() != 1)
		throw std::runtime_error("Wrong token");
		else if (std::isdigit(token[0]))
			st.push(token[0] - '0');
		else if (token == "*" || token == "/" || token == "+" || token == "-")
		{
			if (st.empty())
				throw std::runtime_error("Missing first operand");
			long b = st.top();
			st.pop();
			if (st.empty())
				throw std::runtime_error("Missing second operand");
			long a = st.top();
			st.pop();
			long res;
			if (token == "*")
				res = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Division by zero");
				res = a / b;
			}
			else if (token == "+")
				res = a + b;
			else if (token == "-")
				res = a - b;
			if (res > INT_MAX || res < INT_MIN)
				throw std::runtime_error("Expression value can't be fitted in int data type");
			st.push(res);
		}
		else
			throw std::runtime_error("Wrong token");
	}
	if (st.size() != 1)
		throw std::runtime_error("Wrong expression, stack is not empty");
	return st.top();
}