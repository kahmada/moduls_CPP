#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		static void convert(std::string &str);
};

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

#endif
