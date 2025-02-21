#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (this);
}

bool ScalarConverter::isChar(const std::string& value)
{
	if (value.size() == 1 && !std::isdigit(value))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& value)
{
	
}


