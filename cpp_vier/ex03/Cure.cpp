#include "Cure.hpp"
#include <iostream>

#include "ICharacter.hpp"
Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & other) : AMateria(other) {}

Cure::Cure(AMateria const & amateria) : AMateria(amateria) {
    std::cout << "Cure created from AMateria" << std::endl;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}