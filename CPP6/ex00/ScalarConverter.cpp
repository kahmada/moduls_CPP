#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}


static e_type detectType(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return str[str.length() - 1] == 'f' ? FLOAT : DOUBLE;
	if (str.find('.') != std::string::npos)
{
    size_t dotPos = str.find('.');
    if (dotPos == 0 || dotPos == str.length() - 1 || !isdigit(str[dotPos - 1])) 
	{
        return UNKNOWN;
    }
    for (size_t i = dotPos + 1; i < str.length(); i++)
	{
        if (!isdigit(str[i]) && !(i == str.length() - 1 && str[i] == 'f'))
		{
            return UNKNOWN;
        }
    }

    return str[str.length() - 1] == 'f' ? FLOAT : DOUBLE;
}

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return UNKNOWN;
	}
	return INT;
}

static void displayChar(double value)
{
	std::cout << "char: ";
	if (value < 0 || value > 127 || isnan(value)) 
		std::cout << "impossible\n";
	else if (!isprint(static_cast<char>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";
}

static void displayInt(double value)
{
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || isnan(value))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";
}

static void displayFloat(double value)
{
	std::cout << "float: ";
	if (isnan(value))
		std::cout << "nanf\n";
	else if (isinf(value))
		std::cout << (value > 0 ? "+inff\n" : "-inff\n");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
}

static void displayDouble(double value)
{
	std::cout << "double: ";
	if (isnan(value))
		std::cout << "nan\n";
	else if (isinf(value))
		std::cout << (value > 0 ? "+inf\n" : "-inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << value << "\n";
}

void ScalarConverter::convert(std::string &str)
{
	if (str.empty())
	{
		std::cerr << "Error: Unknown type\n";
		return;
	}
	e_type type = detectType(str);
	double value;
	switch (type)
	{
		case CHAR:
			value = static_cast<double>(str[0]);
			break;
		case INT:
			value = static_cast<double>(std::strtol(str.c_str(), NULL, 10));
			break;
		case FLOAT:
			value = static_cast<double>(std::strtof(str.c_str(), NULL));
			break;
		case DOUBLE:
			value = std::strtod(str.c_str(), NULL);
			break;
		default:
			std::cerr << "Error: Unknown type\n";
			return;
	}
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

