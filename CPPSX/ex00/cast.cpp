#include "cast.hpp"

static e_type detectType(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return str.back() == 'f' ? FLOAT : DOUBLE;
	if (str.find('.') != std::string::npos)
		return str.back() == 'f' ? FLOAT : DOUBLE;

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
	e_type type = detectType(str);

	try
	{
		double value;
		switch (type)
		{
		case CHAR:
			value = static_cast<double>(str[0]);
			break;
		case INT:
			value = std::stoi(str);
			break;
		case FLOAT:
			value = std::stof(str);
			break;
		case DOUBLE:
			value = std::stod(str);
			break;
		default:
			std::cerr << "Error: Unknown type\n";
			return;
		}
	// alors ici on a la value et on la cast n plusieur types selon le code acci si la valeur est char 
		displayChar(value);
		displayInt(value);
		displayFloat(value);
		displayDouble(value);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
}

















/*
En C++, les casts permettent de convertir une variable d'un type à un autre. Il existe plusieurs types de casts :

C-style cast : (type)variable (simple mais risqué).
Static_cast : Vérifie la conversion à la compilation, utilisé pour les conversions sûres entre types compatibles.
Dynamic_cast : Vérifie à l'exécution, utilisé pour les conversions de pointeurs ou références dans une hiérarchie de classes polymorphiques.
Const_cast : Ajoute ou supprime le qualificatif const.
Reinterpret_cast : Force une conversion brutale sans vérification (dangereux).
*/