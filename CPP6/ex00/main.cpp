#include "cast.hpp"

#include "cast.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>\n";
		return 1;
	}

	std::string input = argv[1];
	ScalarConverter::convert(input);

	return 0;
}
