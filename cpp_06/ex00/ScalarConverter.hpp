#ifndef SCALAR_CONVERTER_HPP_
#define SCALAR_CONVERTER_HPP_

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(ScalarConverter& other);
	~ScalarConverter();
	static bool isChar(const std::string& value);
	static bool isInt(const std::string& value);
	static bool isFloat(const std::string& value);
	static bool isDouble(const std::string& value);
	static void convertChar(const std::string& value);
	static void convertInt(const std::string& value);
	static void convertFloat(const std::string& value);
	static void convertDouble(const std::string& value);

public:
	static void convert(const std::string& value);
};

#endif //SCALAR_CONVERTER_HPP_