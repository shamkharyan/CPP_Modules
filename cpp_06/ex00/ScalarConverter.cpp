#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

bool ScalarConverter::isChar(const std::string& value)
{
	if (value.size() == 1 && !std::isdigit(value[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& value)
{
	std::stringstream ss(value);
	std::string remain;
	int i;

	if (ss >> i)
	{
		ss >> remain;
		return remain.empty();
	}
	return false;
}

bool ScalarConverter::isFloat(const std::string& value)
{
	std::stringstream ss(value);
	std::string remain;
	float f;

	if (ss >> f)
	{
		ss >> remain;
		return (remain == "f");
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string& value)
{
	std::stringstream ss(value);
	std::string remain;
	double d;

	if (ss >> d)
	{
		ss >> remain;
		return remain.empty();
	}
	return false;
}

void ScalarConverter::convertChar(const std::string& value)
{
	std::stringstream ss(value);
	char c;

	ss >> c;

	std::cout << "char: ";
	if (c >= 32 && c <= 126)
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << "* not visible *" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& value)
{
	std::stringstream ss(value);
	int i;

	ss >> i;

	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << '\'' << static_cast<char>(i) << '\'' << std::endl;
	else if (i >= 0 && i < 128)
		std::cout << "* non displayable *" << std::endl;
	else
		std::cout << "* imposible *" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(const std::string& value)
{
	std::stringstream ss(value);
	float f;

	ss >> f;

	std::cout << "char: ";
	if (f >= 32 && f <= 126)
		std::cout << '\'' << static_cast<char>(f) << '\'' << std::endl;
	else if (f >= 0 && f < 128)
		std::cout << "* non displayable *" << std::endl;
	else
		std::cout << "* imposible *" << std::endl;

	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& value)
{
	std::stringstream ss(value);
	double d;

	ss >> d;

	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << '\'' << static_cast<char>(d) << '\'' << std::endl;
	else if (d >= 0 && d < 128)
		std::cout << "* non displayable *" << std::endl;
	else
		std::cout << "* imposible *" << std::endl;

	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertSpecial(const std::string& value)
{
	std::cout << "char: *imposible* " << std::endl;
	std::cout << "int: *imposible* " << std::endl;
	if (value == "-inff" || value == "+inff" || value == "nanf")
	{
		std::cout << "float: " << value << std::endl;
		std::cout << "double: " << value.substr(0, value.size() - 1) << std::endl;
	}
	else if (value == "-inf" || value == "+inf" || value == "nan")
	{
		std::cout << "float: " << value + "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	else
	{
		std::cout << "float: *imposible* " << std::endl;
		std::cout << "double: *imposible* " << std::endl;
	}
}

void ScalarConverter::convert(const std::string& value)
{
	if (isChar(value))
		convertChar(value);
	else if (isInt(value))
		convertInt(value);
	else if (isFloat(value))
		convertFloat(value);
	else if (isDouble(value))
		convertDouble(value);
	else
		convertSpecial(value);
}

