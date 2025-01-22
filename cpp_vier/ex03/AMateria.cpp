#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(){}
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used at " << target.getName() << " *" << std::endl;
}
