#ifndef CAST_HPP
#define CAST_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarConverter);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

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
